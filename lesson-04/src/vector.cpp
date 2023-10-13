#include <iostream>
#include <vector>

struct MetaVector
{
    MetaVector() { data_ = {1,2,3}; };
    MetaVector(const MetaVector&) = default;

    MetaVector operator+(const MetaVector&rhs)
    {
        MetaVector res;
        for (size_t i = 0; i < rhs.data_.size() && i < data_.size(); ++i)
        {
            res.data_.push_back( rhs.data_[i] + data_[i] );
        }
        return res;
    }

    MetaVector operator+(int32_t rhs)
    {
        MetaVector res;
        res.data_.push_back(rhs);
        return res;
    }

    const int32_t & operator[](size_t i)
    {
        return data_[i];
    }
    friend std::ostream& operator<<(std::ostream& out, const MetaVector& vector);
private:
    std::vector<int32_t> data_;
};

std::ostream& operator<<(std::ostream& out, const MetaVector& vector)
{
    for (auto el : vector.data_)
    {
        out << el << ", ";
    }
    out << std::endl;
    return out;
}

int main()
{
    MetaVector v1;
 //   v1.data_ = {1,2,3};
    MetaVector v2;
 //   v2.data_ = {4,5,6,7};
    MetaVector v3 = v2 + v1;
 //   v3 = v3 + 10;
 /*   for(auto el : v3.data_)
    {
        std::cout << el << std::endl;
    }
    std::cout << v3[0] << std::endl;
*/
    std::cout << v3 << std::endl;
}
