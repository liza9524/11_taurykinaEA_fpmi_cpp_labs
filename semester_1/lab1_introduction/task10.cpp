#include <iostream>
int main() {
	int n, m, s, h;
	m = 0;
	s = 0;
	h = 0;
	std::cout << "Enter a natural 6-digit number: ";
	std::cin >> n;
	for (int i = 0; i < 3; i++) 
	{
		m = n % 10;
		n = n / 10;
		s = s + m;
	}

	for (int i = 0; i < 3; i++)
	{
		m = n % 10;
		n = n / 10;
		h = h + m;

	}
	if (h == s)
		std::cout << "the number is happy";
	else 
		std::cout << "the number isn't happy";
	return 0;
}