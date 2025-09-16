#include <iostream>
int main() {
	short n, m, sum;
	std::cout << "Enter natural number: ";
	std::cin >> n;
	m = 1;
	sum = 0;
	for (int i = 0; i <n; i++)
	{
		std::cout << i << std::endl;
			m = 2 * i + 1;
			sum = sum + m;
	}
	std::cout <<"The sum of odd numbers" << sum;

	return 0;
}