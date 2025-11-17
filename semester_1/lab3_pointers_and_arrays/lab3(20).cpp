#include <iostream>

int FindSum(int* arr, int n);
void FindMax(int* arr, int n);
void DeleteElements(int* arr, int n, int left_board, int right_board);

int main()
{
    int arr[1000], upper_board, lower_board, n, left_board, right_board;
    bool how;

    std::cout << "Enter the amount of elemens: ";
    std::cin >> n;

    if ((n <= 0) || (n > 1000)||(!std::cin) return 0;
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


    //task 20.1

    std::cout << std::endl << "number of element such that sum of elements before it differs leats from the sum of el after it is " << FindSum(arr, n) << std::endl;
    //task 20.2

    FindMax(arr, n);

    //extra
    std::cout << "enter segment boards ";
    std::cin >> left_board >> right_board;
    DeleteElements(arr, n, left_board, right_board);




    return 0;
}


int FindSum(int* arr, int n) {
    int sumBefore = 0, sumAfter = 0, j, num = 0;
    for (int i = 1; i < n; i++)
    {
        sumAfter += arr[i];
    }
    int compare = sumAfter;

    for (int i = 1; i < n; i++)
    {
        sumBefore += arr[i - 1];
        sumAfter -= arr[i];

        j = sumBefore - sumAfter;
        if (abs(j) <= compare)
        {
            compare = abs(j);
            num = i + 1;
        }

    }
    return num;
}

void FindMax(int* arr, int n) {
    int max = arr[0], position = 0;
    {
        for (int i = 1; i < n; i++)
            if (max < arr[i])
            {
                max = arr[i];
                position = i + 1;
            }
    }
    std::cout << "max element is " << max << " " << "number of max element is " << position << std::endl;
}

void DeleteElements(int* arr, int n, int left_board, int right_board) {
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (!(left_board <= arr[i] && arr[i] <= right_board))
        {
            if (i != k) arr[k] = arr[i];
            ++k;
        }
    }

    for (int i = k; i < n; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}

