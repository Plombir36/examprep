#include <iostream>
#include <string>

#define has(a) find(a) != string::npos

using namespace std;

int sum(string s)
{
	int c = 0;
	for (char n : s)
	{
		c += n - '0';
	}
	return c;
}

bool isprime(int n)
{
	if (n <= 1)
		return false;

	for (int i = 2; i *  i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

// this function is unnecessary
bool check(string s)
{
	cout << "string A: " << s << " size: " << s.size() << endl;

	while (s.find("00") == string::npos)
	{
		if (s.has("033"))
			s.replace(s.find("033"), 3, "21120");
		if (s.has("034"))
			s.replace(s.find("034"), 3, "22120");
		if (s.has("04"))
			s.replace(s.find("04"), 2, "220");
		if (s.has("030"))
			s.replace(s.find("030"), 3, "100");
	}

	cout << "string B: " << s << " size: " << s.size() << endl;
	cout << "sum is: " << sum(s) << endl;

	return isprime(sum(s));
}

int count(string s, char c)
{
	int n = 0;
	for (char i : s)
	{
		n += i == c;
	}

	return n;
}

int main()
{
	string s;

	for (int j = 0; j < 31; j++)
	{
		s += '4';
	}

	for (int j = 0; j < 15; j++)
	{
		s.replace(j*2, 2, "34");
		cout << "checking..." << endl;
		if (check('0' + s + "30")) // alternative: if (isprime(sum(s) + 1))
		{
			cout << "success!" << endl;
			cout << "3 occurs " << count(s, '3') + 1 << " times" << endl;
			cout << "4 occurs " << count(s, '4') << " times" << endl;
			return 0;
		}
		else
		{
			cout << "failed!" << endl << endl;
		}
	}

	// just copypasted the previous one, replacing "34" with "33"
	for (int j = 0; j < 15; j++)
	{
		s.replace(j*2, 2, "33"); // the only difference
		cout << "checking..." << endl;
		if (check('0' + s + "30"))
		{
			cout << "success!" << endl;
			cout << "3 occurs " << count(s, '3') + 1 << " times" << endl;
			cout << "4 occurs " << count(s, '4') << " times" << endl;
			return 0;
		}
		else
		{
			cout << "failed!" << endl << endl;
		}
	}

	return 0;
}
