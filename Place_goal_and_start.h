template<typename T> 
int place_goal_and_start( \
        vector< vector< vector<T> > > & map,\
        const T (&symbols)[3],\
        const int (&dim)[3]=(2,2,1), \
        bool has_goal = false,\
        bool has_start = false,\
        int (&goal)[3] = (0,0,0),\
        int (&start)[3] = (0,0,0))
{
    using namespace std;
    //function that places a door (exit condition) and a point (starting
    //condition) on the map, while avoiding obstacles
     
    int x = rand() % dim[0];
    int y = rand() % dim[1];
    int z = rand() % dim[2];

    if(map[x][y][z] == symbols[0])
    {
       place_goal_and_start(map,dim,false,false); 
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
        place_goal_and_start(map,dim,has_goal,has_start,goal); 
    }
    return;
}
