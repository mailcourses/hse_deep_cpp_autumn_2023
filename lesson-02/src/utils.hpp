#include <iostream>

std::string convert_from_int(int32_t i);

int32_t convert_to_int(const std::string &str);

class Allocator
{
public:
    bool foo(/*Allocator* this*/) { return true; }
    static bool boo() { return false; }
private:
    int64_t data_[10000000000000];
};
