#include <stdexcept>
#include <string>
using namespace std;

namespace fhdo_pk2{
    class empty_stack_exception : public logic_error {
        public:
        empty_stack_exception(string info) : logic_error(info){};
    };
}