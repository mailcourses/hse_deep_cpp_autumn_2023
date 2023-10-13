#include <iostream>
#include <type_traits>

enum ProductCategory
{
    PC_NONE = 0,
    FOOD = 1,
    TV = 2,
    PHONES = 3
};

enum class ProductSubcategory
{
    PC_NONE = 0,
    FRUITS = 1,
    MOBILE_PHONES = 2
};

enum class HttpCode
{
    OK = 200,
    NO_CONTENT = 204,
    NOT_FOUND = 404,
    TIMEOUT = 501
};

struct Response
{
};

HttpCode fetchURL(const std::string& url, Response& response)
{
    return HttpCode::OK;
}

ProductSubcategory detectProductSubcategory()
{
    return ProductSubcategory::PC_NONE;
}

ProductCategory detectProductCategory()
{
    return PC_NONE;
}

template<class E>
auto to_underlying_type(E e)
{
    return static_cast<std::underlying_type_t<E>>(e);
}

class Dachshund
{
public:
    Dachshund(int age, float length, std::string& name) : age(age), length(length), name(name)
    {
    }
    //! Конструктор по умолчанию
    Dachshund() {}
    //! Деструктор
    ~Dachshund(){}
    //! Копирующий конструктор
    Dachshund(const Dachshund&) = default;
    //! Оператор копирования
    //Dachshund& operator==(const Dachshund& rhs) {}
    //! Конструктор перемещения
    Dachshund(Dachshund &&) {}
    //! Оператор перемещения
    //Dachshund& operator==(Dachshund&& rhs) {}
public:
    // В сантиметрах!!!
    float length;
    int age;
    std::string name;
};

int main()
{
    ProductCategory category = detectProductCategory();
    ProductSubcategory subcategory = detectProductSubcategory();
    std::cout << category << std::endl;
    std::cout << to_underlying_type<ProductSubcategory>(subcategory) << std::endl;

    // Dachshund
    Dachshund dog1;
    std::cout << "Age of dog1 is " << dog1.age << std::endl;
    dog1.age = 7;
    Dachshund dog2 = dog1;
    std::cout << "Age of dog2 is " << dog1.age << std::endl;
    std::string dachshund_name = "Roksy";
    Dachshund dog3(3, 50.f, dachshund_name);
}
