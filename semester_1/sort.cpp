#include <iostream>
using namespace std;

void BubleSort(int* arr, int n);

int main() 
{
	const int SIZE = 1000;
	int arr[SIZE], n;
	cin >> n;
	if ((n > 0)||(n>SIZE))
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = -50 + rand() % 100;
			cout << arr[i] << " ";
		}
		cout << endl;
		BubleSort(arr, n);
	}
	else return 0;

	return 0;
}

void BubleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
			if (abs(arr[j]) > abs(arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
			}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}