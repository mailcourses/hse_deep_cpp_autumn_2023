#include <iostream>
#include <vector>

struct Logger
{
    void write(const std::string& str)
    {
        buffer.push_back(str);
        if (buffer.size() > capacity)
        {
            std::cout << "Start flushing buffer" << std::endl;
            for (auto line : buffer)
                std::cout << line << std::endl;
            buffer.clear();
        }
    }
    std::vector<std::string> buffer;
    size_t capacity = 8;
};

struct Daemon
{
    void process(size_t i) const
    {
        logger.write("Some log " + std::to_string(i));
    }
    mutable Logger logger;
};

int main()
{
    Daemon searcher;
    for (size_t i = 0; i < 10; ++i)
        searcher.process(i);
}
