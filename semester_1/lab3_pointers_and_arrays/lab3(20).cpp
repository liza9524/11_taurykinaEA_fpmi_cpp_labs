#include <iostream>

int main()
{
    int arr[1000], sumaft = 0, sumbef = 0, upper_board, lower_board, change, left_board = 0, right_board, compare = 11110, max;
        int how, j = 0, i,n;

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
    int num;
    for ((i = 0); (i < n); i++)
    {
        sumaft += arr[i];
    }
    sumaft -= arr[0];

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
    std::cout << std::endl <<"the number of element that the sum of the elements before it differs the least from the sum of the elements after it is " << num << std::endl;

    //task 20.2
     max = arr[0];
    for (i = 1; (i <= n); i++)
        if (max < arr[i])
        {
            max = arr[i];
            j = i;
        }
    std::cout <<"the biggest element is "<< max << std::endl << " the number of the biggest element is " << (j + 1) << std::endl;


    //extra

    j = 0;
    std::cout << "enter lower board of  section";
    std::cin >> left_board;
    std::cout << "enter upper board of  section";
    std::cin >> right_board;
    if (left_board > right_board)
    {
        change = left_board;
        left_board = right_board;
        right_board = change;
    }

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
        arr[i] = 0;

    for (int i = 0; i < n; i++) 
        std::cout << arr[i] << ' ';






    return 0;
}