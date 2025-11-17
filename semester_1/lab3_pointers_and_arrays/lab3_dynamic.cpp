#include <iostream>
#include <cmath>
int FindSumBetweenZeros(int* arr, int n);
void TransformArray(int* arr, int n);


void FindMaxElement(int* arr, int n);

int main()
{
    int* arr = new int[1000];
    int  i, upper_board, lower_board, n, temp;
    int how;

    std::cout << "Enter the amount of elemens: ";
    std::cin >> n;

    if ((n <= 0) || (n > 1000)) return 0;
    std::cout << "enter 0, if the elements of array are entered randomly" << std::endl << "Enter 1 if the elements of array are entered by hand" << std::endl;

    std::cin >> how;
    switch (how)
    {
    case(1):

        for (int i = 0; i < n; i++)
        {
            std::cout << "enter the element number" << (i + 1) << " ";
            std::cin >> arr[i];
        }
        break;

    case(0):

        std::cout << "Enter the lower board of array";
        std::cin >> lower_board;
        std::cout << "Enter the upper board of array";
        std::cin >> upper_board;
        if (lower_board > upper_board)
        {
            int temp = lower_board;
            lower_board = upper_board;
            upper_board = temp;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = lower_board + rand() % (upper_board - lower_board);
            std::cout << arr[i] << " ";
        }
        break;

    default:

        std::cout << "ONLY 1 OR 0";
        return 0;

    }

    std::cout << std::endl;
    //task 38.2
    try {
        std::cout << "sum of elements between zeros is " << FindSumBetweenZeros(arr, n);
    }
    catch (const char* ErrorMessage) {
        std::cout << ErrorMessage;
    }
    std::cout << std::endl;
    //extra
    TransformArray(arr, n);

    std::cout << std::endl;
    //task 38.1
    FindMaxElement(arr, n);

    delete[] arr;
    arr = nullptr;
    return 0;
}

int FindSumBetweenZeros(int* arr, int n)
{
    int  FirstZeroIndex = -1, LastZeroIndex = -1, sum = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
        {
            FirstZeroIndex = i;
            break;
        }
    for (int i = n - 1; i >= FirstZeroIndex; i--)
        if (arr[i] == 0)
        {
            LastZeroIndex = i;
            break;
        }
    if ((FirstZeroIndex == -1) && (LastZeroIndex == -1))
    {
        throw "Error! No zero in the array";
        return 0;
    }
    if (FirstZeroIndex == LastZeroIndex)
    {
        throw "Error! Only one zero in the array";
        return 0;
    }
    if (LastZeroIndex - FirstZeroIndex == 1)
    {
        throw "Error! No elements between zeros";
        return 0;
    }

    for (int i = FirstZeroIndex; i < LastZeroIndex; i++)
    {
        sum += arr[i];
    }

    return sum;
}


void TransformArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if ((arr[i] < 0) && (arr[j] >= 0))
            {
                std::swap(arr[i], arr[j]);
            }

    }
    std::cout << "transformed array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}


void FindMaxElement(int* arr, int n) {
    int i, PositiveIndex, MinMultiplicity;
    for (i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
    }

    int* counter = new int[1000] {};


    for (i = 0; i < n; i++)
    {
        PositiveIndex = arr[i] + abs(arr[n - 1]);
        counter[PositiveIndex]++;
    }


    MinMultiplicity = 1000;
    for (i = 0; i < n; i++)
    {
        PositiveIndex = arr[i] + abs(arr[n - 1]);
        if ((MinMultiplicity > counter[PositiveIndex]) && (counter[PositiveIndex] != 0))
            MinMultiplicity = counter[PositiveIndex];
        if (MinMultiplicity == 1) break;
    }



    for (i = 0; i < n; i++)
    {
        PositiveIndex = arr[i] + abs(arr[n - 1]);

        if (counter[PositiveIndex] == MinMultiplicity)
        {
            std::cout << "the biggest element which occurs " << counter[PositiveIndex] << " times is " << arr[i];
            delete[] counter;
            counter = nullptr;
            break;
        }
    }

}