#include "utils.hpp"

std::string convert_from_int(int32_t i)
{
    return std::to_string(i);
}

int32_t convert_to_int(const std::string &/*str*/)
{
    return 100500;
}
