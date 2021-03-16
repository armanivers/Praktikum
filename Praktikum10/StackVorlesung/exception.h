#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <string>
#include <stdexcept>

class empty_stack_exception:public std::out_of_range{
 public:
 empty_stack_exception(std::string info):out_of_range(info){}
};
#endif