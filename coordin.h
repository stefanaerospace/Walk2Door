//coordin.h -- holds function prototypes
#ifndef COORDIN_H_
#define COORDIN_H_

using namespace std;

#include<vector>


template<typename T>
void place_obst(\
        vector< vector< vector<T> > > & map3d, \
        const T (&symbols)[3], \
        const int (&dim)[3],\
	int obst_chance=20);

//TODO make this a template function again
void place_goal_and_start( \
        vector< vector< vector<char> > > & map,\
        const char (&symbols)[3],\
        const int (&dim)[3], \
        int (&goal)[3],\
        int (&start)[3],\
        bool has_goal,\
        bool has_start);

template<typename T>
void pathfinder(\
        vector< vector< vector<T> > > & world,\
        const T (&symbols)[3],\
        const int (&dim)[3], \
        int (&goal)[3],\
        int (&start)[3],\
        bool goal_reached=false);

#include"Place_obst.h"
#include"Place_goal_and_start.h"
#include"Pathfinder.h"
#endif
