#include <iostream>
#include <string>
#include "stack.h"

int main(){
  Stack<double> s {};
  Stack<std::string> u {};

  u.push("Start");
  std::cout << u.pop() << std::endl;

  int i;
  for(i = 1; i<=100; i++){
    s.push(i*0.5);
  }

  for(i = 0; i<100 ; i++){
    std::cout << s.pop() << std::endl;
  }

  // exception testing
  //std::cout << s.pop() << std::endl;

  return 0;
}