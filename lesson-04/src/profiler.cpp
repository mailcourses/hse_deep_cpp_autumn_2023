#include <iostream>
#include <chrono>
#include <source_location>

class Profiler
{
public:
    Profiler(const std::source_location &location =
                   std::source_location::current());
    ~Profiler();
private:
    std::chrono::time_point<std::chrono::system_clock> start_ts_;
    std::string name_;
    std::source_location location_;
};

Profiler::Profiler(const std::source_location &location)
{
    location_ = location;
    start_ts_ = std::chrono::system_clock::now();
}

Profiler::~Profiler()
{
    auto end_ts = std::chrono::system_clock::now();
    uint64_t duration = std::chrono::duration_cast<std::chrono::microseconds>(end_ts - start_ts_).count();
    std::cout << "Execution of '" << location_.function_name() << "' function is "  << duration << " microseconds" << std::endl;
}

void foo()
{
    Profiler prof;
    for(size_t i = 0; i < 1000000; ++i);
}

void boo()
{
    Profiler prof;
    for(size_t i = 0; i < 5000000; ++i);
}

int main()
{
    foo();
    boo();
}
