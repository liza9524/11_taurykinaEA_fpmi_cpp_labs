#include <iostream>

int Sum(int* arr, int n);
void Max(int* arr, int n);
void DeleteElements(int* arr, int n, int left_board, int right_board);

int main()
{
    int arr[1000], i, upper_board, lower_board, n, temp, left_board, right_board;
    bool how;

    std::cout << "Enter the amount of elemens: ";
    std::cin >> n;

    if ((n <= 0) || (n > 1000)) return 0;
    std::cout << "enter 0, if the elements of array are entered randomly" << std::endl << "Enter 1 if the elements of array are entered by hand";

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
        for ((i = 0); (i < n); i++)
        {
            arr[i] = lower_board + rand() % (upper_board - lower_board);
            std::cout << arr[i] << " ";
        }
    }
    else
    {
        std::cout << "ONLY 1 OR 0";
        return 0;
    }

    //task 20.1

    std::cout << std::endl << "number of element such that sum of elements before it differs leats from the sum of el after it is " << Sum(arr, n) << std::endl;
    //task 20.2

    Max(arr, n);

    //extra
    std::cout << "enter segment boards ";
    std::cin >> left_board >> right_board;
    DeleteElements(arr, n, left_board, right_board);




    return 0;
}


int Sum(int* arr, int n) {
    int sumbef = 0, sumaft = 0, i = 0, j, num = 0;
    for ((i = 1); (i < n); i++)
    {
        sumaft += arr[i];
    }
    int compare = sumaft;

    for ((i = 1); (i < n); i++)
    {
        sumbef += arr[i - 1];
        sumaft -= arr[i];

        j = sumbef - sumaft;
        if (abs(j) <= compare)
        {
            compare = abs(j);
            num = i + 1;
        }

    }
    return num;
}

void Max(int* arr, int n) {
    int max = arr[0], i, num;
    for (i = 1; (i <= n); i++)
        if (max < arr[i])
        {
            max = arr[i];
            num = i;
        }
    std::cout << "max element is " << max << " " << "number of max element is " << (num + 1) << std::endl;
}

void DeleteElements(int* arr, int n, int left_board, int right_board) {
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (not (left_board <= arr[i] && arr[i] <= right_board))
        {
            if (i != k) arr[k] = arr[i];
            ++k;
        }
    }

    for (int i = k; i < n; i++) arr[i] = 0;

    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
}

