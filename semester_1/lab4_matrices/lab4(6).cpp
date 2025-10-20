#include <iostream>
#include<iomanip>
int main()
{
    int arr[100][100], j = 0, i = 0, upper_board, lower_board, strings, columns, change = 0, k=0, sum=0,how;

    std::cout << "Enter the number of columns";
    std::cin >> columns;
        std::cout << "Enter the number of strings"; 
    std::cin>> strings;

    if ((strings <= 0) || (strings > 1000) || (columns <= 0) || (columns > 1000)) return 0;
    std::cout << "enter 0, if the elements of array are entered randomly" << std::endl << "Enter 1 if the elements of array are entered by hand ";

    std::cin >> how;
    if (how == 1)
    {
        for ((i = 0); (i < columns); i++)
        {
            for ((j = 0); (j < strings); j++)
                std::cout << "enter the element number" << (i + 1) << " ";
            std::cin >> arr[i][j];
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
        for ((i = 0); (i < columns); i++)
        {
            for ((j = 0); (j < strings); j++)
                arr[i][j] = lower_board + rand() % (upper_board - lower_board);
           
        }
        for ((i = 0); (i < columns); i++)
        {
            for ((j = 0); (j < strings); j++)
            {
                std::cout <<std::setw(3)<< arr[i][j] << " ";
            }std::cout << std::endl;
        }
    }
   
    else
    {   std::cout << "ONLY 1 OR 0";
        return 0;
    }
    std::cout << std::endl;
   //6.1
    for ((i = 0); (i < columns); i++)
    {
        k = 0;
        for ((j = 0); (j < strings); j++)
            if (arr[i][j] == 0) k = 1;
        if (!(k == 1))
        {
            for ((j = 0); (j < strings); j++)
                sum += arr[i][j];
        }
    }
    std::cout <<"sum of elements is "<< sum;
    std::cout << std::endl;
    //6.2 
   
    for ((i = 0); (i < columns); i++)
    {
        k = strings - 1;

        for ((j = 0); (j < strings/2); j++)
        {
            change = arr[i][j];
            arr[i][j] = arr[i][k];
            arr[i][k] = change;
            
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
    return 0;
}