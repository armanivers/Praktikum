#include <stdexcept>
#include <string>
using namespace std;

namespace fhdo_pk2{
    class invalid_dimensions : public logic_error {
        public:
        invalid_dimensions(string info) : logic_error(info){};
    };
}