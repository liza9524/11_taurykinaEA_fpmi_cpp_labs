#include <iostream>
#include <cmath>
void SumBetweenZeros(int* arr, int n);
void TransformArray(int* arr, int n);


int MaxEl(int* arr, int n);

int main()
{
    int* arr = new int[1000];
    int  i, upper_board, lower_board, n, temp;
    int how;

    std::cout << "Enter the amount of elemens: ";
    std::cin >> n;

    if ((n <= 0) || (n > 1000)) return 0;
    std::cout << "enter 0, if the elements of array are entered randomly" << std::endl << "Enter 1 if the elements of array are entered by hand ";

    std::cin >> how;
    if (how == 1)
    {
        for ((i = 0); (i < n); i++)
        {
            std::cout << "enter the element number" << (i + 1) << " ";
            std::cin >> arr[i];
        }
    }
    else if (how == 0)
    {
        std::cout << "Enter the lower board of array: ";
        std::cin >> lower_board;
        std::cout << "Enter the upper board of array: ";
        std::cin >> upper_board;
        if (lower_board > upper_board)
        {
            temp = lower_board;
            lower_board = upper_board;
            upper_board = temp;
        }
        for ((i = 0); (i < n); i++)
        {
            arr[i] = lower_board + rand() % (upper_board - lower_board);
            std::cout << arr[i] << " ";
        }
    }
    else
    {
        std::cout << "ONLY 1 OR 0!!!";
        return 0;
    }

    std::cout << std::endl;


    //task 38.2

    SumBetweenZeros(arr, n);

    std::cout << std::endl;
    //extra
    TransformArray(arr, n);

    std::cout << std::endl;
    //task 38.1


    std::cout << "the biggest element which occurs less often is " << MaxEl(arr, n);

    delete[] arr;
    arr = nullptr;
    return 0;
}

void SumBetweenZeros(int* arr, int n)
{
    int i, j = 0, a = 0, sum = 0;
    for (i = 1; (i <= n); i++)
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    for (i = n; (i >= 0); i--)
        if (arr[i] == 0)
        {
            a = i;
            break;
        }
    if (j == a)
    {
        std::cout << "This action cannot be performed on this array" << std::endl;
    }
    else
    {
        for ((i = j); (i < a); i++)
        {
            sum += arr[i];
        }
        std::cout << std::endl << "sum of elements between 0s is " << sum;
    }

}


void TransformArray(int* arr, int n) {
    int i, min = 0, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
            if ((arr[i] < 0) && (arr[j] >= 0))
            {
                min = arr[i];
                arr[i] = arr[j];
                arr[j] = min;
            }

    }
    std::cout << "transformed array: ";
    for (i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}


int MaxEl(int* arr, int n) {
    int i, j, AbsNum, min;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
            if (arr[i] < arr[j])
            {
                min = arr[i];
                arr[i] = arr[j];
                arr[j] = min;
            }
    }

    int* counter = new int[1000] {};


    for (i = 0; i < n; i++)
    {
        AbsNum = arr[i] + abs(arr[n - 1]);
        counter[AbsNum]++;
    }


    min = 1000;
    for (i = 0; i < n; i++)
    {
        AbsNum = arr[i] + abs(arr[n - 1]);
        if ((min > counter[AbsNum]) && (counter[AbsNum] != 0))
            min = counter[AbsNum];
        if (min == 1) break;
    }

    std::cout << std::endl;


    for (i = 0; i < n; i++)
    {
        AbsNum = arr[i] + abs(arr[n - 1]);

        if (counter[AbsNum] == min)
        {

            return arr[i];
            delete[] counter;
            counter = nullptr;
            break;
        }
    }

}