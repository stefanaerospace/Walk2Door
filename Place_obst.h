template<typename T> 
void place_obst(\
        vector< vector< vector<T> > > & map3d, \
        const T (&symbols), \
        const int (&dim)[3] = (2,2,1), \
        int obst_chance = 20)
{
    //function that manipulates the given 3D map and inserts obstacles into it
    //    the obs_chance is the percent chance an obstacle should be placed 
    //    there.
    
    for(int x=0; x<= dim[0]-1; x++)
    {
        for(int y=0; y <= dim[1]-1; y++)
        {
            for(int z=0; z <= dim[2]-1; z++)
            { 
                int obst = rand() % 100;

                if((obst % 100) <= obst_chance)
                {
                    map3d[x][y][z] = symbols[0];
                }
            }
        }
    }
    return;
}
