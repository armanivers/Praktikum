#include <iostream>
#include <string>
#include "stack.h"
#include "exception.h"

int main(){
  Stack<double> s {};
  //Stack<std::string> u {};

  //u.push("Start");
  //std::cout << u.pop() << std::endl;

  int i;
  for(i = 1; i<=100; i++){
    s.push(i);
  }

  for(i = 0; i<100 ; i++){
    std::cout << s.pop() << std::endl;
  }

  try
  {
    // exception testing
    std::cout << s.pop() << std::endl;
  }
  catch(empty_stack_exception& e)
  {
    std::cout << e.what() << std::endl;
  }
  
  return 0;
}