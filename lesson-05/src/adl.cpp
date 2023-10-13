#include <iostream>

namespace X {
    struct A {
        int a;
        double b;
        std::string c;
    };
    std::ostream& operator<<(std::ostream& out, const A& value) { return out; }
    void foo(const A& value) { }
}

void foo(const X::A& value) { }

int main()
{
    X::A a;
    std::cout << a;
    foo(a);
}
