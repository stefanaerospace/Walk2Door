#include<stdlib.h>
#include<iostream>
#include<vector>
#include"coordin.h"

int main()
{
    using namespace std;
    
    int goal[3]  = {0,0,0};
    int start[3] = {0,0,0};
    const char sym[3]  = {'*','G','S'}; 
    const int dim[3]   = {20,20,1};
    vector< vector< vector<char> > > map3d\
        (dim[0],vector<vector<char> >(dim[1],vector<char>(dim[2],'.')));
    
    place_obst(map3d,sym,dim);
    
    place_goal_and_start(map3d,sym,dim,goal,start);
    
    pathfinder(map3d,sym,dim,goal,start);
    
    print_floor(map3d,dim);
}

