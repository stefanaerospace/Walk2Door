#include<stdlib.h>
#include<iostream>
#include<vector>
#include"coordin.h"

int main()
{
    using namespace std;
    
    int goal[3]  = {0,0,0};
    int start[3] = {0,0,0};
    const char sym[3]  = {'X','G','S'}; 
    const int dim[3]   = {20,20,1};
    vector< vector< vector<char> > > map3d\
        (dim[0],vector<vector<char> >(dim[1],vector<char>(dim[2])));
    
    cout<<"\n\nStarted, placing obstacles...\n\n";
    place_obst(map3d,sym,dim);

    cout<<"\n\nFinished placing obstacles, now setting start and goal...\n\n";
    place_goal_and_start(map3d,sym,dim,goal,start);

    cout<<"\n\nFinished placing a goal and start. Finding a path...\n\n";
    pathfinder(map3d,sym,dim,goal,start);
}

