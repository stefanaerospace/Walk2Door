#include<vector>
#include<iostream>

using namespace std;
void wormhole(\
        vector< vector< vector<char> > > & world,\
        const char (&symbols)[3],\
        const int (&dim)[3], \
        int (&goal)[3],\
        int (&start)[3],\
        bool & goal_reached,\
        int choice = 0)
{

   int move_dir[3]= {start[0],start[1],start[2]}; 

   switch(choice)
   {
       case 0://move forward in the x direction
            move_dir[0] += 1;   
            break;
       case 1://move backward in the x direction
            move_dir[0] -= 1;       
            break;
       case 2://y dir
            move_dir[1] += 1; 
            break;
       case 3:
            move_dir[1] -= 1; 
            break;
       case 4://z dir
            move_dir[2] += 1;
            break;
       case 5:
            move_dir[2] -= 1; 
            break;
       //if there are no exits, backtrack-- 6-11 aren't needed, 
       //but they keep the code readable
       case 6:
            move_dir[0] += 1; 
            break;
       case 7:
            move_dir[0] -= 1; 
            break;
       case 8:
            move_dir[1] += 1; 
            break;
       case 9:
            move_dir[1] -= 1; 
            break;
       case 10:
            move_dir[2] += 1; 
            break;
       case 11:
            move_dir[2] -= 1; 
            break;

       case 12:
            goal_reached = true;
           world[move_dir[0]][move_dir[1]][move_dir[2]] = symbols[2];
           break;
   } 

   cout<<"\n\n    Wormhole: made it through switch statement, case: "<<choice<<endl;
   //boundary check
   if((0<=move_dir[0] && move_dir[0]<dim[0] && 0<=move_dir[1] && move_dir[1]<dim[1] &&\
           0<=move_dir[2] && move_dir[2]<dim[2]) && goal_reached == false)
   {
       cout<<"\n    Wormhole:step is inside the bounds";
       //find nearest exit--pick goal or unexplored block
       if(choice<=5)
       {
          //pick goal if able
          if(world[move_dir[0]][move_dir[1]][move_dir[2]]==symbols[1])
          {
             cout<<"\n    Wormhole:next step is Goal.\n";
             goal_reached = true;
          }
          //if an obstacle or previously explored keep searching
          else if(world[move_dir[0]][move_dir[1]][move_dir[2]]==symbols[0] &&\
                  world[move_dir[0]][move_dir[1]][move_dir[2]]==symbols[2])
          {
            cout<<"\n    Wormhole:Step should not be taken...tying again.";
            wormhole(world,symbols,dim,goal,start,goal_reached,(choice+1));     
          }
          else
          {
            cout<<"\n    Wormhole:Step taken in choices 0-5\n";
            start[0] = move_dir[0];//TODO see if the copy function would be better 
            start[1] = move_dir[1];
            start[2] = move_dir[2];
          }

       }
       //with better solutions taken, block off current point and backtrack 
       else if(choice<12 && choice>5)
       {
           cout<<"\n    Wormhole:Choice is 6+.";
            if( world[move_dir[0]][move_dir[1]][move_dir[2]]==symbols[2])
            {
                cout<<"\n    Wormhole:Backtracking.";
                world[start[0]][start[1]][start[2]] = symbols[0];
                start[0] = move_dir[0];//TODO see if the copy function would be better 
                start[1] = move_dir[1];
                start[2] = move_dir[2];
            }
             
            else
            {
                cout<<"\n    Wormhole:backtracking failed. Trying again.\n";
                wormhole(world,symbols,dim,goal,start,goal_reached,(choice+1));
            }

       }
   }
   //if current choice is out of bounds and hasn't hit choice 12
   else if(goal_reached==false)
   {
       cout<<"\n    Wormhole: choice is not inside bounds, trying again";
       wormhole(world,symbols,dim,goal,start,goal_reached,(choice+1));
   
   }

}
