/*
 * Pathfinder.h
 *
 * Implements a basic beeline path finder, if it hits an obstacle, it passes
 *      the choice on to Wormhole.h
 */

#include<cmath>
#include<algorithm>
#include<iostream>
#include"coordin.h"
#include"Wormhole.h"

template<typename T>
void pathfinder(\
        vector< vector< vector<T> > > & world,\
        const T (&symbols)[3],\
        const int (&dim)[3], \
        int (&goal)[3],\
        int (&start)[3],\
        bool goal_reached)
{
    using namespace std;

    //determine the direction that the point should march in
    int vec[3] = {(int)abs(goal[0]-start[0]),(int)abs(goal[1]-start[1]), \
            (int)abs(goal[2]-start[2])};
   
    int move_dir;
    if(vec[2]<=vec[0] && vec[1]<=vec[0])
    {
       move_dir = 0;
    }
    if(vec[0]<=vec[1] && vec[2]<=vec[1])
    {
       move_dir = 1;
    }
    if(vec[1]<=vec[2] && vec[0]<=vec[2])
    {
        move_dir = 2;
    } 
    
    start[move_dir] += 1;
    
    //bounds check--if vector fails take the nearest exit
    if(start[move_dir] < 0 || start[move_dir] > dim[move_dir])
    {
        start[move_dir]-=1;
        world[start[0]][start[1]][start[2]] = symbols[0];
        wormhole(world,symbols,dim,goal,start,goal_reached);
    } 

    //symbols check--make sure that the point isn't moving onto an obstacle
    else if(world[start[0]][start[1]][start[2]] != symbols[0] && \
            world[start[0]][start[1]][start[2]] != symbols[2])
    {
       if(world[start[0]][start[1]][start[2]] == symbols[1])
       {
           goal_reached = true;
       }
       else
       {
           world[start[0]][start[1]][start[2]] = symbols[2];
           pathfinder(world,symbols,dim,goal,start,goal_reached);
       }
    }
    //if heading into an obstacle, block off current position and backtrack
    else
    {
        world[start[0]][start[1]][start[2]] = symbols[0];        
        start[move_dir]-=1;
        wormhole(world,symbols,dim,goal,start,goal_reached);
    }

    if(goal_reached == false)
    {
        pathfinder(world,symbols,dim,goal,start,goal_reached);
    }
}
