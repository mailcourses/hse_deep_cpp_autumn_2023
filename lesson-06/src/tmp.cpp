#include <cassert>

class A {
private:
    virtual void test() {}
};
class B : public A {  };
class C : public A {  };

int main()
{
    A* a = new C;
    C* c = dynamic_cast<C*>(a);
    assert( c != nullptr );
}

