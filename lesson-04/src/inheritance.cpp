#include <iostream>

class Animal
{
public:
    Animal() = default;
    Animal(uint8_t age) : age_(age) {}
    Animal(const std::string& name, uint8_t weight, uint8_t age) : name(name), weight_(weight), age_(age) {}
    virtual ~Animal()
    {
        std::cout << "Dtor::Animal" << std::endl;
    }
    virtual void info()
    {
        std::cout << "Undefined info" << std::endl;
    }
protected:
    void feed()
    {
        std::cout << "Undefined feed" << std::endl;
    }
public:
    std::string name;
protected:
    uint8_t weight_;
private:
    uint8_t age_;
};

class Ape : public Animal
{
public:
    Ape(const std::string& name) : Animal(name, 30, 4) {}
    void info() override
    {
        std::cout << "Ape sound" << std::endl;
        //std::cout << "Ape age = " << age_ << std::endl;
        std::cout << "Ape weight = " << weight_ << std::endl;
        std::cout << "Ape name = " << name << std::endl;
    }
    void get_banana()
    {
        std::cout << "Ape::get_banana" << std::endl;
    }
    ~Ape()
    {
        std::cout << "Dtor::Ape" << std::endl;
    }
};

class Dog : public Animal
{
public:
    Dog(const std::string& name) : Animal(name, 30, 4) {}
    void info() override
    {
        std::cout << "Dog sound" << std::endl;
        //std::cout << "Ape age = " << age_ << std::endl;
        std::cout << "Dog weight = " << weight_ << std::endl;
        std::cout << "Dog name = " << name << std::endl;
        data = new int;
    }
    ~Dog()
    {
        std::cout << "Dtor::Dog" << std::endl;
        delete data;
    }
    int *data;
};

void get_info(Animal *animal)
{
    // dog.info()
    // ape.info()
    animal->info();
    Ape *ape = dynamic_cast<Ape*>(animal);
    if (ape)
    {
        ape->get_banana();
    }
    else
    {
        std::cout << "Bad cast to Ape*" << std::endl;
    }
    delete animal;
}

void animal_cast(Animal &animal)
{
    // dog.info()
    // ape.info()
    Ape& ape = dynamic_cast<Ape&>(animal);
    ape.get_banana();
}


int main()
{
    std::cout << "Sizeof Animal = " << sizeof(Animal) << std::endl;
    std::cout << "Sizeof Ape = " << sizeof(Ape) << std::endl;
    std::cout << "Sizeof Dog = " << sizeof(Dog) << std::endl;
    Ape *ape = new Ape("Ceaser");
    Dog *dog = new Dog("Roksy");
    animal_cast(*ape);
    //animal_cast(*dog);
    get_info(ape);
    get_info(dog);
}
