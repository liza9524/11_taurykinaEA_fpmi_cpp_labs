#include <iostream>
#include <vector>
#include <numeric>
#include<functional>
#include <cmath>
#include <unordered_set>
#include <algorithm>
void Print(std::vector<int>v)
{
    for (std::vector<int>::iterator i = v.begin(); i < v.end(); i++)
    {
        std::cout << *i << " ";
    }
}
int FindMax(std::vector<int>v)
{
    return *max_element(v.begin(), v.end());
}
int FindMin(std::vector<int>v)
{
    return *min_element(v.begin(), v.end());
}
int FindSum(std::vector<int> v)
{
    return std::accumulate(v.begin(), v.end(), 0);
}

int FindAmountOfNumbers(std::vector<int> v)
{
    return v.size();
}
int FindAmountOfEqualNumbers(std::vector<int> v, int n)
{
    return std::count_if(v.begin(), v.end(), std::bind2nd(std::equal_to<int>(), n));
}

int FindAmountOfGreaterNumbers(std::vector<int> v, int n)
{
    return  std::count_if(v.begin(), v.end(), std::bind2nd(std::greater<int>(), n));
}
void ChangeZeros(std::vector<int>& v)
{
    int medium = FindSum(v) / FindAmountOfNumbers(v);
    std::replace(v.begin(), v.end(), 0, medium);
}
void ChangeEvenNumbers(std::vector<int>& v)
{
    std::replace_if(v.begin(), v.end(), [](int x) {return x % 2 == 0; }, (FindMax(v) - FindMin(v)));
}

void AddRangeSum(std::vector<int>& v, int RangeBegin, int RangeEnd)
{
    int sum = std::accumulate(v.begin() + RangeBegin, v.begin() + RangeEnd + 1, 0);

    for (int& i : v) { i += sum; }
}

void RemoveRepeatedElements(std::vector<int>& v)
{
    std::unordered_set<int> temp;
    std::vector<int> res;

    for (int x : v) {
        if (temp.find(std::abs(x)) == temp.end()) {
            res.push_back(x);
            temp.insert(std::abs(x));
        }
    }
    v = res;
}

int main() {
    int n;
    std::vector<int> v{ 1,2,0,42,67,52,0,4,17 };


    std::cout << "sum of elements in vector is " << FindSum(v) << std::endl;

    std::cout << "there are " << FindAmountOfNumbers(v) << " elements in vector" << std::endl;

    std::cout << "Enter a natural number to find equals: ";
    std::cin >> n;
    std::cout << "there are " << FindAmountOfEqualNumbers(v, n) << " elements equal to " << n << std::endl;

    std::cout << "Enter a natural number to compare: ";
    std::cin >> n;
    std::cout << "there are " << FindAmountOfGreaterNumbers(v, n) << " elements more than " << n << std::endl;

    ChangeZeros(v);
    std::cout << "vector, where inserted arithmetic mean instead of zeros: ";
    Print(v);

    int LeftBard, RightBoard;
    std::cout << std::endl << "enter the left board of range: ";
    std::cin >> LeftBard;
    std::cout << "enter the right board of range: ";
    std::cin >> RightBoard;
    if (LeftBard > RightBoard) std::swap(LeftBard, RightBoard);
    if ((LeftBard != RightBoard) && (RightBoard > 0) && (LeftBard >= 0) && (RightBoard < v.size()))
    {
        AddRangeSum(v, LeftBard, RightBoard);
        std::cout << "vector, where sum of elements of range is added to each element: ";
        Print(v);
    }
    else std::cout << "Wrong Boards input!";
    std::cout << std::endl;

    ChangeEvenNumbers(v);
    std::cout << "vector, where all even numbers changed to difference between max and min elements: ";
    Print(v);
    std::cout << std::endl;

    RemoveRepeatedElements(v);
    std::cout << "vector, where with removed repeated elements: ";
    Print(v);

    return 0;
}