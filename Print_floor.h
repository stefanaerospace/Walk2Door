#include<iostream>
#include"coordin.h"

template<typename T>
void print_floor(\
        vector< vector< vector<T> > > & world,\
        const int (&dim)[3])
{
   for(int i = 0; i<dim[0]; i++)
   {
       for(int j = 0; j<dim[1]; j++)
       {
           cout<<world[i][j][0];
       }

        cout<<endl;
   }
}
