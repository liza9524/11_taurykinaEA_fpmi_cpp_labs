#include <iostream>

int main() 
{
    int a = 0, b = 1, n;
    std::cout << "Enter natural number n: ";
    std::cin >> n;
    for (int i = a;
        i <= n;
        i += 1)
    {
        if (i % 2 == 0)
            a += i;
        else b *= i;
    }
    std::cout << "The sum of even numbers: " << a << std::endl << "The product of odd numbers: " << b;

    return 0;
}