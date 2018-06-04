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
        int (&start)[3])
{
    using namespace std;

    bool greached = false;//this flags if the goal has been reached or not
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
    cout<<start[move_dir]<<endl;
    
    start[move_dir] += ((goal[move_dir]-start[move_dir])/(int)abs(goal[move_dir]-start[move_dir]));
    
    //bounds check--if vector fails take the nearest exit
    if(start[move_dir] < 0 || start[move_dir] > dim[move_dir])
    {
        start[move_dir] -= ((goal[move_dir]-start[move_dir])/(int)abs(goal[move_dir]-start[move_dir])); 
        world[start[0]][start[1]][start[2]] = symbols[0];
        wormhole(world,symbols,dim,goal,start,greached);
    } 

    //symbols check--make sure that the point isn't moving onto an obstacle
    else if(world[start[0]][start[1]][start[2]] != symbols[0] && \
            world[start[0]][start[1]][start[2]] != symbols[2])
    {
       cout<<"\n\nIn first else if statement\n\n";
       if(world[start[0]][start[1]][start[2]] == symbols[1])
       {
           cout<<"\n\nPathfinder:Pathfinder finds goal\n\n";
           greached = true;
           cout<<greached<<endl;
       }
       else
       {
           cout<<"\n\nPathfinder:Placing moving to new space\n\n";
           world[start[0]][start[1]][start[2]] = symbols[2];
           pathfinder(world,symbols,dim,goal,start);
       }
    }
    //if heading into an obstacle, block off current position and backtrack
    else
    {
        cout<<"\n\nPathfinder:final else statment\n\n";
        start[move_dir] -= ((goal[move_dir]-start[move_dir])/(int)abs(goal[move_dir]-start[move_dir])); 
        world[start[0]][start[1]][start[2]] = symbols[0];        
        wormhole(world,symbols,dim,goal,start,greached);
    }

    if(greached == false)
    {
        cout<<"\n goal reach status:"<<greached<<endl;
        print_floor(world,dim);
        pathfinder(world,symbols,dim,goal,start);
    }
}
