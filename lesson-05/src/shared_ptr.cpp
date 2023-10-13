#include<iostream>

using T = int64_t;

class shared_ptr
{
public:
    shared_ptr();
    shared_ptr(T* obj);
    shared_ptr(const shared_ptr& other);
    shared_ptr(shared_ptr&& other);

    shared_ptr& operator=(const shared_ptr& other);
    shared_ptr& operator=(shared_ptr&& other);

    ~shared_ptr();
private:
    void decrement_and_delete();
private:
    struct counter
    {
        size_t cnt = 0;
        T* obj = nullptr;
    };
    counter *counter_ = nullptr;
};

void
shared_ptr::decrement_and_delete()
{
    if (counter_)
    {
        counter_->cnt -= 1;
        if (counter_->cnt == 0)
        {
            std::cout << "Delete object..." << std::endl;
            delete counter_->obj;
            delete counter_;
        }
    }
}

shared_ptr::shared_ptr()
{
    std::cout << "Ctor::shared_ptr empty" << std::endl;
}

shared_ptr::shared_ptr(T* obj)
{
    std::cout << "Ctor::shared_ptr" << std::endl;
    counter_ = new counter();
    counter_->obj = obj;
    counter_->cnt += 1;
}

shared_ptr::shared_ptr(const shared_ptr& other)
{
    counter_ = other.counter_;
    if (counter_)
    {
        counter_->cnt += 1;
    }
    std::cout << "Ctor::shared_ptr copy" << std::endl;
}

shared_ptr::shared_ptr(shared_ptr&& other)
{
    std::cout << "shared_ptr::shared_ptr(&&)" << std::endl;
    counter_ = other.counter_;
    other.counter_ = nullptr;
}

shared_ptr&
shared_ptr::operator=(const shared_ptr& other)
{
    /*
     * shared_ptr ptr1(new T);
     * ptr1 = ptr1;
     */
    if (&other == this)
    {
        return *this;
    }
    decrement_and_delete();
    counter_ = other.counter_;
    if (counter_)
    {
        counter_->cnt += 1;
    }
    std::cout << "shared_ptr::operator=" << std::endl;
    return *this;
}

shared_ptr&
shared_ptr::operator=(shared_ptr&& other)
{
    std::cout << "shared_ptr::operator=(&&)" << std::endl;
    // shared_ptr ptr1;
    // ptr1 = std::move(ptr1);
    if (&other == this)
    {
        return *this;
    }

    decrement_and_delete();

    counter_ = other.counter_;
    other.counter_ = nullptr;
    return *this;
}

shared_ptr::~shared_ptr()
{
    if (counter_)
    {
        std::cout << "counter=" << counter_->cnt << std::endl;
    }
    decrement_and_delete();
    std::cout << "Dtor::shared_ptr" << std::endl;
}

int main()
{
    shared_ptr ptr1(new T(100500));
    shared_ptr ptr2(ptr1);
    shared_ptr ptr3(new T(500100));
    ptr3 = ptr2;
    {
        shared_ptr ptr3;
        ptr3 = ptr2;
    }
    {
        shared_ptr ptr4;
    }

    shared_ptr ptr5(std::move(ptr2));
    shared_ptr ptr6;
    ptr6 = std::move(ptr5);
    std::cout << "end" << std::endl;
}
