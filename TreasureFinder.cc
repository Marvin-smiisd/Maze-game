#include <iostream>
#include "TreasureFinder.h"

using namespace std;

TreasureFinder::TreasureFinder() {
    nRow = 0;
    nCol = 0;
    found = 0;
}

void TreasureFinder::mapReader() {
     ifstream inFile;
     char fileName[16];
     cout << " \n\t\t\t\tPlease input the file name: ";
     cin >> fileName;
     cout<<"\n\n";
     // open file
     inFile.open(fileName);
     //handle error
     if (inFile.fail())
        {
         cout << " Input file opening failed! \n\n ";
        }
     // read the size.
     inFile >> nRow >> nCol;
     // allocate the memory
     maze  = new char*[nRow];
     for (int i = 0; i<nRow; i++)
         maze[i] = new char[nCol]; // create the columns for each row.

     // and read the array.

     for (int i =0; i<nRow; i++){cout << "\t\t\t\t\t ";
         for (int j=0; j<nCol; j++) {
             inFile >> maze[i][j];
             cout <<maze[i][j];
             if (maze[i][j] == 'M') {
                me.r = i;
                me.c = j;
                }
             }
             cout << endl;
          }
     found = 0;
     inFile.close();
}


point TreasureFinder::get_me() {
      return me;
}


bool TreasureFinder::pathCheck(int x, int y) { // it's true if it's not wall or having been passed.
          if (maze[x][y] != 'W' && maze[x][y] != 'w' && maze[x][y] != 'P' && maze[x][y] != ' ') return true;
       else return false;
}

// We use 'P' to indicate this has been passed.
//(space) ' ' when we backtrack to differentiate with 'P' and it is easier to keep track of the program's running.
void TreasureFinder::find(int x, int y) {
     point temp;
     temp.r = x;
     temp.c = y;
     travel.push(temp);       // push the position to stack TRAVEL.
     insertLink(temp); // create a new link with the position of x & y.
      // mark it as having been passed.
     if (maze[x][y] == 'T' || maze[x][y] == 't')  {
        found ++;      // we found 1 more treasure.
        printList();   // we print the list.
     }
     maze[x][y] = 'P';    // mark as having been passed.
     cout << endl;
     printMaze();         // print out the maze.
     cin.get();
     cout << "\t\t\t\t\tSearching.... enter to go on.\n";
     //cin.get();           // wait for enter.
     //system("pause");

     // go to the directions.
     if (pathCheck(x-1,y)) find(x-1,y); // to the North.
     if (pathCheck(x+1,y)) find(x+1,y); // to the South.
     if (pathCheck(x,y+1)) find(x,y+1); // to the East.
     if (pathCheck(x,y-1)) find(x,y-1); // to the West.
     // Come back to the later position from the stack record.
     me = travel.top();
     maze[me.r][me.c] = ' ';
     travel.pop();        // remove the old position from the stack.
     deleteLink();        // delete the unused link at the end of the list.
}

void TreasureFinder::printMaze() {
     for (int i =0; i<nRow; i++){cout << "\t\t\t\t\t ";
         for (int j=0; j<nCol; j++) cout<<maze[i][j];
             cout << endl;
          }
}


int TreasureFinder::get_found() {
     return found;
}

// insert a new link at the end of the linked list.
void TreasureFinder::insertLink(point data) {
     // allocated a memory location for a new link.
     link *temp, *current;
     temp = new link;
     temp->value = data;
     temp->next = NULL;
     path = temp;
     if (path != NULL) {
        //current = path; // keep track of the path.
        while (path->next !=NULL) //{
              path=path->next;
        }
     path->next = new link;
     path>= path->next;
     path->next = NULL;
     path->value = data;      // current(last) -> next = temp;
     //}
     //else path = temp;              // path itself points to temp since path is NULL.
}

// delete the link at the end of the linked list.
void TreasureFinder::deleteLink() {
     link *temp, *current;
     current = path;
     // if there are more than one links in the list.
     if (path->next != NULL) {
        while (current->next !=NULL) {
              temp = current;        // keep track of the previous link.
              current=current->next;
        }
        temp->next = NULL;           // points to nothing since the last one is deleted.
     }
     delete current;
}

// print the list.
void TreasureFinder::printList() {
     link * current;
     current = path;
     cout << "\t\t\t\t\t---------------------------------------------\n"
          << " \t\t\t\t\tWe found treasure number " << found << " at the end of the \n \t\t\t\t\tpath displayed below:\n\n";
     while (current != NULL) {//append 'st' to number of treasure found if there were two
              cout << "\t\t\t\t\t (" << current->value.r << ","<< current->value.c << ")\n";
              current = current->next;
           }
     cout << "\t\t\t\t\t---------------------------------------------";
  }
