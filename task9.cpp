#include <iostream>
int main() {
	int n, m, h=0,s=0;
	std::cout << "Enter a natural 4-digit number: ";
	std::cin >> n;
	m = n;
	for(int i = 0; i < 4; i++) 
	{	h = m % 10;
		s = 10*s + h;
		m=m / 10;
		std::cout << s << " " << m << " " << h << std::endl;
	}
	if (n == s) std::cout << "The number is a palindrome";

	return 0;
}