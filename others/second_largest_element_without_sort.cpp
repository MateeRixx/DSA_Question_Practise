#include <bits/stdc++.h>
using namespace std;

//

int second_largest(int arr[], int size)
{
    //
    int max = INT_MIN;
    int second_max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            second_max = max;

            max = arr[i];
        }
        else if (arr[i] > second_max && arr[i] != max)
        {

            second_max = arr[i];
        }
    }

    return second_max;
}

int main()
{

    int arr[5] = {4, 7, 5, 2, 1};
    int size = 5;

    cout << second_largest(arr, size);

    return 0;
}