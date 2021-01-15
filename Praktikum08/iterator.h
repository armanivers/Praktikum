#ifndef _ITERATOR_H_
#define _ITERATOR_H_
namespace fhdo_pk2{
class Iterator{

    public:
    virtual bool hasNext() = 0;
    virtual const char* next() = 0;
};
}
#endif
