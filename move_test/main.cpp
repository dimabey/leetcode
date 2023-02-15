
#include <iostream>
#include <utility>

struct Test
{
    Test(double i) : num{i} {};
    double num = 0;
};

int main()
{
    Test a(10);
    Test b(20);

    std::cout << a.num << std::endl;
    std::cout << b.num << std::endl;

    std::cout << "------------" << std::endl;

    a = std::move(b);

    std::cout << a.num << std::endl;
    std::cout << b.num << std::endl;

    std::cout << "------------" << std::endl;

    Test* a_ptr = &a;
    Test* b_ptr = &b;

    std::cout << a_ptr << std::endl;
    std::cout << b_ptr << std::endl;

    std::cout << "------------" << std::endl;

    b_ptr->num = 15;

    a_ptr = std::move(b_ptr);

    std::cout << a_ptr << std::endl;
    std::cout << b_ptr << std::endl;

    return 0;
}
