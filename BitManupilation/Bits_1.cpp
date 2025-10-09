#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string int_to_binaray(int n)
{
	string result;

	while (n > 0)
	{
		if (n % 2 ==1)
		{
			result +='1';
		}

		else
		{

			result +='0';
		}

		n = n / 2;
	}
	reverse(result.begin(), result.end());

	return result;
}

int main()
{

int n=8;
cout<<int_to_binaray(n);

}

