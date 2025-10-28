#include <iostream>

int Sum(int* arr, int n);
void Max(int* arr, int n);
void DeleteElements(int* arr, int n, int left_board, int right_board);

int main()
{
    int arr[1000], sumaft = 0, sumbef = 0, j = 0, i, upper_board, lower_board, n, change, left_board = 0, right_board, compare = 11110;;
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
            change = lower_board;
            lower_board = upper_board;
            upper_board = change;
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

    std::cout << std::endl << Sum(arr, n) << std::endl;
    //task 20.2

    Max(arr, n);

    //extra

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
    std::cout << max << " " << (num + 1) << std::endl;
}

void DeleteElements(int* arr, int n, int left_board, int right_board) {
    size_t k = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (not (left_board <= arr[i] && arr[i] <= right_board))
        {
            if (i != k) arr[k] = arr[i];
            ++k;
        }
    }

    for (size_t i = k; i < n; i++) arr[i] = 0;

    for (size_t i = 0; i < n; i++) std::cout << arr[i] << ' ';
}

