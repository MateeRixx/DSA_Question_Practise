#include <iostream>
#include <algorithm>
using namespace std;

bool check_set_bit(int n, int i)
{
    return (n & (1 << i)) != 0;
}

int main()
{

    int n = 13;

    cout << check_set_bit(n, 2);

    return 0;
}