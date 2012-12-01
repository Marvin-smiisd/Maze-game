#include <cstdlib>
#include <iostream>
#include "TreasureFinder.h"

using namespace std;

int main()
{
    TreasureFinder myMaze;
    myMaze.mapReader();   // read the maze.
    point start = myMaze.get_me();    // get the position of ME.
    myMaze.find(start.r,start.c);     // find the treasures starting with the position of ME.
    if (myMaze.get_found()>0)         // if there is a non-zero number of treasure.
       cout << "There is/are " << myMaze.get_found() << " reachable treasure(s) in the map.\n";
    else
         cout << "There is no treasure.\n";

         system("pause");
    return 0;
}
