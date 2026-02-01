#include <bits/stdc++.h>
using namespace std;


vector<int> spiralMatrix(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = m - 1;

    vector<int> ans;

    while (top <= bottom && left <= right)
    {

        for (int i = top; i <= right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> sample = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans=spiralMatrix(sample);
    for(auto numbers:ans)
    {
        cout<<numbers<<" ";
        
    }



    return 0;
}
