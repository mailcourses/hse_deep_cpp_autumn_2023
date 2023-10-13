#include <iostream>

class IWriter
{
public:
    virtual void write(const std::string&) = 0;
};

class Printer : public IWriter
{
public:
    Printer(const std::string& ip) {}
    virtual void write(const std::string& line) override
    {
        std::cout << "[Printer] " << line << std::endl;
    }
};

class Console : public IWriter
{
public:
    Console() = default;
    virtual void write(const std::string& line) override
    {
        std::cout << "[Console] " << line << std::endl;
    }
};

class Logger
{
public:
    Logger(IWriter* writer) : writer_(writer)
    {
    }
    void write()
    {
        writer_->write("Hello, world!");
    }
private:
    IWriter* writer_;
};

int main()
{
    Printer *printer = new Printer("localhost");
    Console *console = new Console();
    {
        Logger logger(printer);
        logger.write();
    }
    {
        Logger logger(console);
        logger.write();
    }
    return 0;
}
