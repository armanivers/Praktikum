#ifndef _ITERATOR_H_
#define _ITERATOR_H_
namespace fhdo_pk2{
template <class T>    
class Iterator{

    public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
    virtual ~Iterator(){}
};
}
#endif
