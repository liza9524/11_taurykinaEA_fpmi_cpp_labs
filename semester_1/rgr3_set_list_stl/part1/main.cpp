#include <iostream>
#include <set>

void RemoveNonPrimeNumbers(std::set<int>& PrimeNumbers, int MaxNumber)
{
    for (int i = 2; i <= MaxNumber; i++)
    {
        if (PrimeNumbers.find(i) == PrimeNumbers.end())
        {
            continue;
        }

        for (int j = 2; j * i <= MaxNumber; j++)
        {
            PrimeNumbers.erase(i * j);
        }
    }
}
void Print(std::set<int>& PrimeNumbers) {
    for (int i : PrimeNumbers)
        std::cout << i << " ";
}
int main()
{
    int MaxNumber;
    std::cin >> MaxNumber;
    if (MaxNumber > 1)
    {
        std::set<int>PrimeNumbers;
        for (int i = 2; i <= MaxNumber; i++)
        {
            PrimeNumbers.insert(i);
        }

        RemoveNonPrimeNumbers(PrimeNumbers, MaxNumber);

        std::cout << "Prime numbers not greater than " << MaxNumber << " : ";
        Print(PrimeNumbers);
    }
    else std::cout << "Wrong input!";
    return 0;
}