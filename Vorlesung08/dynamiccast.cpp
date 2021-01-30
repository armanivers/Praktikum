using namespace std;

#include <isostream>

class X{
    public:
        virtual ~X(){}
    };
class A : public X {};
class B : public X {};

void typ_check(X* p){
    A* pa = dynamic_cast<A*>(p);
    if (pa){
        cout << "p zeigt auf ein Objekt von Typ A" << endl;
    } else {
        cout << "P zeigt nicht auf ein Objekt von Typ A" << endl;
    }
}

int main(){
    A a;
    B b;
    typ_check(&a);
    typ_check(&b);
    return 0;
}