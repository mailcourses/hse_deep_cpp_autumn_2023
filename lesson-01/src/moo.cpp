#include <string>

void moo()
{
}

int square(double a)
{
    return static_cast<int>(a * a);
}

/*int square(int a)
{
    return a * a;
}*/

std::string square(int a)
{
    return std::to_string( a * a );
}
