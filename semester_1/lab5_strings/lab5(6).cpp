#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool isnum(const string& s, int a, int b)
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

string FindEvenNums(const string& s)
{
	const string punkmarks = ".,!?;:- ";
	int first_punk = 0;
	int the_lastest = s.find_last_of(punkmarks), last_punk = the_lastest;
	string res = "";
	do
	{
		last_punk = s.find_first_of(punkmarks, first_punk + 1);
		(last_punk < 0) ? (last_punk = s.size() - 2) : (last_punk);
		if (isnum(s, first_punk + 1, last_punk))
		{
			if ((s[last_punk - 1] = '2') || (s[last_punk - 1] = '4') || (s[last_punk - 1] = '6') || (s[last_punk - 1] = '8') || (s[last_punk - 1] = '0'))
			{
				for (int i = first_punk; i < last_punk; i++)
				{
					cout << "bob ";
					res += s[i];

				}
				res += ",,";
			}
		}
		first_punk = last_punk;

	} while (last_punk > 0);
	if (res == "") return "no even nums";
	else return res;

}

int main()
{
	string offer;
	getline(cin, offer);

	cout << "vynik: " << FindEvenNums(offer);

	return 0;
}