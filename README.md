# Walk2Door
A simple C++ program that has a point walk towards a door on a 2D map that has obstacles.

I was told generic functions confused people. I was also told that recursive functions confuse people.

So even though this is a poor use of memory, I made generic functions that are also recursive. 

The algorigthm guides the point to the door just works to minimize the euclidian distance. But since 
  I made the room discrete, the point moves in the direction that has the largest component of the vector pointing to the goal.
  
The program exits once the point has the same coordinates as the goal. 

If the point gets stuck in an obstacle funnel with no exit, the point backtracks one step and places a virtual obstacle 
  where it once was.
  
Currently the program segfaults when it forces itself into the bounds of the room.
