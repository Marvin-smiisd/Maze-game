#include <iostream>
#include <fstream>
#include "stack_template.h"

using namespace std;

struct point{
             int r;
             int c;
       };

struct link{
        point value;
        link *next;
       };


class TreasureFinder{

      public:
             TreasureFinder();              // constructor to set the maze's row and column equal to 0.
             void mapReader();              // read the map into 2-D dynamically allocated array.
             point get_me();                // get the position of me.
             int get_found();               // get how many treasured found.
             void find(int x, int y);       // find the treasures.

      private:
              bool pathCheck(int x, int y); // check if this direction is accessible.
              void insertLink(point data);  // insert the link at the end of the list.
              void deleteLink();            // delete the link at the end of the list.
              void printList();             // print the linked list - the path to treasure.
              void printMaze();             // print the maze.
              int nRow, nCol;               // numbers of row and column of the maze.
              char **maze;                  // maze - 2D dynamically allocated array.
              Stack<point> travel;          // stack to keep track of the way.
              point me;                     // the position of Me.
              link *path;                   // the pointer to the first linked list (path).
              int found;                    // number of found treasures.
      };
