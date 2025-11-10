#include <iostream>
#include<iomanip>
int Sum(int** a, int n, int m);
void reverseCol(int** arr, int columns, int strings);


int main()
{
    int j = 0, i = 0, upper_board, lower_board, strings, columns, temp = 0, how;

    std::cout << "Enter the number of columns";
    std::cin >> columns;
    std::cout << "Enter the number of strings";
    std::cin >> strings;
    int** arr = new int* [columns];
    for (i = 0; i < columns; i++)
        arr[i] = new int[strings];
    if ((strings <= 0) || (strings > 1000) || (columns <= 0) || (columns > 1000)) return 0;
    std::cout << "enter 0, if the elements of array are entered randomly" << std::endl << "Enter 1 if the elements of array are entered by hand ";

    std::cin >> how;
    if (how == 1)
    {
        for ((i = 0); (i < columns); i++)
        {
            for ((j = 0); (j < strings); j++) {
                std::cout << "enter the element number" << (i + 1) << " " << j + 1 << " ";
                std::cin >> arr[i][j];
            }
        }
    }
    else if (how == 0)
    {
        std::cout << "Enter the lower board of array";
        std::cin >> lower_board;
        std::cout << "Enter the upper board of array";
        std::cin >> upper_board;
        if (lower_board > upper_board)
        {
            temp = lower_board;
            lower_board = upper_board;
            upper_board = temp;
        }
        for ((i = 0); (i < columns); i++)
        {
            for ((j = 0); (j < strings); j++)
                arr[i][j] = lower_board + rand() % (upper_board - lower_board);

        }
        for ((i = 0); (i < columns); i++)
        {
            for ((j = 0); (j < strings); j++)
            {
                std::cout << std::setw(3) << arr[i][j] << " ";
            }std::cout << std::endl;
        }
    }

    else
    {
        std::cout << "ONLY 1 OR 0";
        return 0;
    }
    std::cout << std::endl;
    //6.1

    std::cout << "sum of elements is " << Sum(arr, columns, strings);
    std::cout << std::endl;
    //6.2 
    reverseCol(arr, columns, strings);

    for (i = 0; i < columns; i++)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;
    return 0;
}

int Sum(int** a, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                k = 1;
            }
        }
        if (k != 1)
        {
            for (int j = 0; j < m; j++)
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

void reverseCol(int** arr, int columns, int strings)
{
    int i, temp = 0, j, k;
    for ((i = 0); (i < columns); i++)
    {
        k = strings - 1;

        for ((j = 0); (j < strings / 2); j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[i][k];
            arr[i][k] = temp;

            k--;
        }

    }

    for ((i = 0); (i < columns); i++)
    {
        for ((j = 0); (j < strings); j++)
        {
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << std::endl;

    }
}