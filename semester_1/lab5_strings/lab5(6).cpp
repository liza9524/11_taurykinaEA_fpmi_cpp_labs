#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool isnum(string s, int a, int b)
{
	for (int i = a; i < b; i++)
	{
		if (!isdigit(s[i]))
		{
			return false;
		}
	}
	return true;
}

string FindEvenNums(string s)
{
	const string punkmarks = " _ { } [ ] # ( ) < > % : ; ? * + - / ^ & | ~ ! ";
	int first_punk = -1;
	int last_punk = s.find_last_of(punkmarks);
	string res = "";
	do
	{
		last_punk = s.find_first_of(punkmarks, first_punk + 1);
		if (last_punk < 0)
		{
			last_punk = s.size() - 1;
		}
		if (isnum(s, first_punk + 1, last_punk))
		{
			if ((s[last_punk - 1] == '2') || (s[last_punk - 1] == '4') || (s[last_punk - 1] == '6') || (s[last_punk - 1] == '8') || (s[last_punk - 1] == '0'))
			{
				for (int i = first_punk + 1; i < last_punk; i++)
				{
					res += s[i];
				}
				res += ",,";
			}
		}
		first_punk = last_punk;

	} while (last_punk > 0);

	if (res == "")
	{
		return "no even nums";
	}

	return res;
}

int main()
{
	string offer;
	getline(cin, offer);
	cout << "vynik: " << FindEvenNums(offer);

	return 0;
}