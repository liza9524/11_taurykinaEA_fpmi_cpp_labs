#include <iostream>
#include<iomanip>
int FindSum(int** a, int n, int m);
void ReverseColumns(int** arr, int columns, int strings);
void PrintArray(int** arr, int columns, int strings);

int main()
{
    int  cols, strings, how;

    std::cout << "Enter the number of strings: ";
    std::cin >> strings;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
    int** arr = new int* [strings];
    for (int i = 0; i < strings; i++)
        arr[i] = new int[cols];
    if ((cols <= 0) || (cols > 1000) || (strings <= 0) || (strings > 1000))
    {
        std::cout << "Wrong input!";
        return 0;
    }
    std::cout << "enter 0, if the elements of array are entered randomly" << std::endl << "Enter 1 if the elements of array are entered by hand ";

    std::cin >> how;
    switch (how)
    {
    case 1:

        for (int i = 0; i < strings; i++)
        {
            for (int j = 0; j < cols; j++) {
                std::cout << "enter the element from " << i + 1 << " colum at position " << j + 1 << " ";
                std::cin >> arr[i][j];
            }
        }
        break;

    case 0:
        int upper_board, lower_board, temp;
        std::cout << "Enter the lower board of array";
        std::cin >> lower_board;
        std::cout << "Enter the upper board of array";
        std::cin >> upper_board;
        if (lower_board > upper_board)
        {
            std::swap(lower_board, upper_board);
        }
        for (int i = 0; i < strings; i++)
        {
            for (int j = 0; j < cols; j++)
                arr[i][j] = lower_board + rand() % (upper_board - lower_board);

        }

        break;


    default:

        std::cout << "ONLY 1 OR 0";
        return 0;

    }
    PrintArray(arr, strings, cols);
    //6.1

    std::cout << "sum of elements in strings without zeros is " << FindSum(arr, strings, cols);
    std::cout << std::endl;
    //6.2 
    ReverseColumns(arr, strings, cols);

    for (int i = 0; i < strings; i++)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;
    return 0;
}
void PrintArray(int** arr, int columns, int strings)
{
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < strings; j++)
        {
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int FindSum(int** a, int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            for (int j = 0; j < m; j++)
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

void ReverseColumns(int** arr, int columns, int strings)
{
    int i, temp = strings / 2, j, k;
    for (int i = 0; i < columns; i++)
    {
        k = strings - 1;
        for (int j = 0; j < temp; j++)
        {
            std::swap(arr[i][j], arr[i][k]);
            k--;
        }

    }
    std::cout << "Transformed Array: " << std::endl;
    PrintArray(arr, columns, strings);
}