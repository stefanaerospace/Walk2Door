//Tried to get this to work as a recursive template, turns out that is a bit more than
//	I am willing to chew at this moment.
#include<stdlib.h>
#include"coordin.h"
using namespace std;
void place_goal_and_start( \
        vector< vector< vector<char> > > & map,\
        const char (&symbols)[3],\
        const int (&dim)[3], \
        int (&goal)[3],\
        int (&start)[3],\
        bool has_goal=false,\
        bool has_start=false)
{
    
    //function that places a door (exit condition) and a point (starting
    //condition) on the map, while avoiding obstacles
     
    int x = rand() % dim[0];
    int y = rand() % dim[1];
    int z = rand() % dim[2];

    if(map[x][y][z] == symbols[0])
    {
       place_goal_and_start(map,symbols,dim,goal,start,has_goal,has_goal); 
    }
    
    else if(has_goal == false)
    {
        map[x][y][z] = symbols[1];
        goal[0] = x;
        goal[1] = y;
        goal[2] = z;
        has_goal = true;
    }

    if(map[x][y][z] != symbols[0] && map[x][y][z] != symbols[1] && has_goal == true)
    {
        map[x][y][z] = symbols[2];
        start[0] = x;
        start[1] = y;
        start[2] = z;       
        has_start = true;
    }
    else
    {
        place_goal_and_start(map,symbols,dim,goal,start,has_goal,has_start); 
    }
    return;
}


