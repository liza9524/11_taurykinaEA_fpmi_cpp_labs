#include<iostream>
int main()
{
	int n, paln = 0, sqrn = 0, palSqrn = 0, l = 0, num = 0;
	std::cout << "enter natural number: ";
	std::cin >> n;
<<<<<<< HEAD
=======

>>>>>>> bb22c8262c06c2e83e431456e151447bba396fae
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
			if (paln == i && sqrn == palSqrn) std::cout << paln << " ";
			i++;
			paln = 0;
			sqrn = 0;
		}
	}
	else { std::cout << "ERROR!!!"; }

	return 0;
}
