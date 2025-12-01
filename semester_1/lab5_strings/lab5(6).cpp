#include <iostream>
#include <string>
#include <cstring>
bool IsNumber(std::string s, int a, int b)
{
	for (int i = a + 1; i < b; i++)
	{
		if (!isdigit(s[i]))
		{
			return false;
		}
	}
	return true;
}

std::string FindEvenNums(std::string s)
{
	const std::string punkmarks = ":;?-!., ";
	int first_punk = -1;
	int last_punk = -1;
	std::string res = "";
	while (last_punk != s.find_last_of(punkmarks))
	{
		last_punk = s.find_first_of(punkmarks, first_punk + 1);

		if (IsNumber(s, first_punk, last_punk))
		{
			if ((s[last_punk - 1] == '2') || (s[last_punk - 1] == '4') || (s[last_punk - 1] == '6') || (s[last_punk - 1] == '8') || (s[last_punk - 1] == '0'))
			{
				if (!res.empty())
				{
					res += ",,";
				}
				for (int i = first_punk + 1; i < last_punk; i++)
				{
					res += s[i];
				}
			}
		}
		first_punk = last_punk;

	}

	last_punk = s.size();

	if (IsNumber(s, s.find_last_of(punkmarks), last_punk))
	{
		if ((s[last_punk - 1] == '2') || (s[last_punk - 1] == '4') || (s[last_punk - 1] == '6') || (s[last_punk - 1] == '8') || (s[last_punk - 1] == '0'))
		{

			if (!res.empty())
			{
				res += ",,";
			}
			for (int i = first_punk + 1; i < last_punk; i++)
			{
				res += s[i];
			}
		}
	}

	if (res == "")
	{
		return "no even nums";
	}

	return res;
}

int main()
{
	std::string offer;
	std::cout << "enter the string: ";
	getline(std::cin, offer);
	std::cout << "result: " << FindEvenNums(offer);

	return 0;
}