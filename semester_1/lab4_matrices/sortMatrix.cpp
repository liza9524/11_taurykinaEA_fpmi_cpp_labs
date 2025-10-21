#include <iostream>
#include<iomanip>

bool ascCamp(int a, int b) {
    return a < b;
}

void bubblesort(int**arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (arr[i][j] < arr[i][j+1]) {
                int change = arr[i][j];
                arr[i][j] = arr[i][j + 1];
                arr[i][j + 1] = change;
            }
        }
    }
}


void merge(int** arr, int n, int m,int k,int**temp) {
    int t = n;
    int i = m;
    int j = n;

    for (int g = 0; g < n; g++)
    {
        int t = n;
        int i = m;
        int j = n;
        while ((t < m) && (i < k))
            if (arr[g][t] <= arr[g][i]) 
            {
                temp[g][k] = arr[g][t];
                t++;
            }
            else {
                temp[g][k] = arr[g][i];
                i++;
            }
        while (t < m)
            temp[g][k] = arr[g][t];
        t++; k++;
        while (i < k)
            temp[g][k] = arr[g][i];
        i++; k++;
    }

}
void mergesort(int** arr, int left, int right,int**temp) 
{
    if (right - left <= 1) return;
    int mid = (left + right) / 2;
    mergesort(arr, left, mid,temp);
    mergesort(arr, mid, right,temp);
    merge(arr, left, mid, right, temp);
}


void SortInsert(int**a, int n,int m)
{
    int x; long i, j,l;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            x = a[i][j];
            for (l = j - 1; (i >= 0) && (a[i][l] > x); i--)
                a[i][j + 1] = a[i][j];
                a[i][j + 1] = x;
        }
    }
}
void CountSort(int** arr, int** a, int n, int m) {
    int count[100][100]{};
    int i, j,l;
    for (i = 0; i < n; i++) for (j = 0; j < m; j++)
        count[i][j] = 0;


    for (i = 0; i <n; i++)
    {
        for (j = i + 1; j < m-1; j++)
            for (l= j + 1; l < m; l++)
        {
                if (arr[i][j] < arr[i][l])
                    count[i][j]++;
            else
                count[i][l]++;
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        a[i][count[i][j]] = arr[i][j];
}




int main()
{
    int** arr;
    int** a;
    int j = 0, i = 0, upper_board, lower_board, strings, columns, change = 0, k = 0, sum = 0, how;
    
    std::cout << "Enter the number of columns";
    std::cin >> columns;
    std::cout << "Enter the number of strings";
    std::cin >> strings;

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
                std::cout << std::setw(3) << arr[i][j] << " ";
            }std::cout << std::endl;
        }
    }

    else
    {
        std::cout << "ONLY 1 OR 0";
        for (i = 0; i < columns; i++) {
            delete[] arr[i];
            delete[] a[i];
        }
        delete[] arr;
        arr = nullptr;
        delete[] a;
        a = nullptr;

        return 0;
    }
    std::cout << std::endl;
  
    std::cin >> k;
    switch (k) {
    case 1:
        bubblesort(arr, columns, strings);
        break;
    case 2:
            mergesort(arr,columns,strings,a);
            break;
    case 3:
        SortInsert(arr, columns, strings);
        break;
    case 4:
        CountSort(arr, a, columns, strings);
        break;
    }

    for ((i = 0); (i < columns); i++)
    {
        for ((j = 0); (j < strings); j++)
        {
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (i = 0; i < columns; i++) {
        delete[] arr[i];
        delete[] a[i];
    }
    delete[] arr;
    arr = nullptr;
    delete[] a;
    a = nullptr;


    
    return 0;
}