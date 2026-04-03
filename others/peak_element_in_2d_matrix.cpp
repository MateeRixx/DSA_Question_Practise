int finmaxindex(vector<vector<int>>&mat,int n , int m , int columnNumber)

{
    int maxvalue=-1;
    int index=-1;

    for(int i=0;i<n;i++)
    {
        if(mat[i][columnNumber]>maxvalue)
        {
            maxvalue=mat[i][columnNumber];
            index=i;

        
        }
    }

    return index;

}


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;

       
        int low=0;
        int high=m-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int row_index=finmaxindex(mat,n,m,mid);
            int left=mid-1 > 0 ? mat[row_index][mid-1]:-1;
            int right=mid+1 < m ? mat[row_index][mid+1]:-1;
            
            
            if(mat[row_index][mid]>left && mat[row_index][mid]>right)
            {
                ans={row_index,mid};
                return ans;


            }
            else if(mat[row_index][mid]<left)
            {
                high=mid-1;

            }
            else{
                low=mid+1;

            }
            
        }



    return ans;


    }
};
