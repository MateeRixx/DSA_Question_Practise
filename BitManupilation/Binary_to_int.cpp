
#include<iostream>
#include<string>
using namespace std;

int bin_2_deci(string binary_number)
{
	int len=binary_number.size();
	int p2=1;

	int num=0;

	for(int i=len-1;i>=0;i--)
	{
		if(binary_number[i]=='1')
		{
			num=num+p2;

		}

		p2=p2*2;
	}

	return num;



}


int main()
{
	string binary_number="111000";
	cout<<bin_2_deci(binary_number);

}
