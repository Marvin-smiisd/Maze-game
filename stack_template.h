/*********************************************************************
  Filename: stack_template.h
   Header file for the Stack data structure. It uses a vector to store the 
   data. The class implements the very basics of stacks (pushing, popping 
   elements, a check for whether the stack is empty, and the top element.

*********************************************************************/
#include <vector>

using namespace std;

template <class T> 
class Stack {
 public:
  Stack() {} // intentionally empty
  ~Stack() { data.clear(); }

  // precondition: input is valid
  // postcondition: input is now at the top of the stack 
  void push( T input ) {
    data.push_back( input );
  }

  // precondition: the stack has something in it
  // postcondition: the top element was popped. If the stack was empty, 
  //				do not call thus function.
  void pop() {
    data.pop_back();
  }

  // precondition: the stack has something in it
  // postcondition: return the top element.
  T top() {
    return data.back();
  }

  // precondition: the stack is initialized
  // postcondition: If the stack is empty, then return true.
  bool empty() {
    return data.size()==0;
  }

 private:
  vector<T> data;
};

