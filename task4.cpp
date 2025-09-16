#include <iostream>

int main() {
	int  b = 1, k;
	std::cout << "Enter natural number k ";
	std::cin >> k;
	for (int i = 2;
		i <= k;
		i += 2)
	{
		if (k % 2 == 0)
			b = b * i;
		else b = b * (i + 1);
	}
	std::cout << "The double factorial of a number k: " << b;

	return 0;
}
