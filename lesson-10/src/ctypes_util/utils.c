#include <stdlib.h>
#include <iostream>

int sum(int* arr, int len)
{
    int res = 0;
    for (int i = 0; i < len; ++i)
    {
        res += arr[i];
    }
    return res;
}

int fibonacci(int n)
{
    if (n < 2)
        return 1;
    return fibonacci(n-2) + fibonacci(n-1);
}

int foo(int i)
{
    static int j = 0;
    j += i;
    return j;
}

extern "C"
{
void* convert_to_string(int num)
{
    std::string num_str = std::to_string(num);
    std::cout << "[convertToString] res = " << num_str << std::endl;
    char* res = strdup(num_str.c_str());
    return res;
}

void free_memory(void *ptr)
{
    free(ptr);
}

}
