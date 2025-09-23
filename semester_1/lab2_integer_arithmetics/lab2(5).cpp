#include<iostream>
int main() 
{
	int n, paln = 0, sqrn = 0, palSqrn = 0, l = 0, num = 0;
	std::cout << "enter natural number: ";
	std::cin >> n;
	if (n > 0)
	{
		std::cout << "doube palindrome numbers: ";
		for (int i = 1; (i < n);)
		{
			l = i;
			while (l != 0)
			{
				num = l % 10;
				paln = 10 * paln + num;
				l = l / 10;
			}
			l = i * i;
			palSqrn = i * i;
			while (l != 0)
			{
				num = l % 10;
				sqrn = 10 * sqrn + num;
				l = l / 10;
			}

		}
	}
	else { std::cout << "ERROR!!!"; }

	return 0;
}
