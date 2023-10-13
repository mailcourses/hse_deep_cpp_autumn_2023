#include <iostream>

struct A
{
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }
};

void foo(std::string& str)
{
    str.push_back('a');
}

void foo(const A& a)
{
    std::cout << "foo(A)" << std::endl;
}

int main()
{
    std::string s1("Hello alloc");
    foo(s1);
    //foo(std::string("Bye alloca")); <-- cannot bind non-const lvalue reference of type
    std::cout << "s1=" << s1 << std::endl;
    A a;
    foo(a);
    std::cout << "before" << std::endl;
    foo(A());
    std::cout << "after" << std::endl;
}
