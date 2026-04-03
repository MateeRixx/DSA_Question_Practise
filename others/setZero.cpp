class Solution
{
public:
    void setZeroes(vector<vector<int>> &Matrix)
    {
        int rows = Matrix.size();
        int cols = Matrix[0].size();
        vector<bool> zeroRows(rows, false);
        vector<bool> zeroCols(cols, false);

        // First pass: record rows and columns to be zeroed
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (Matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }

        // Second pass: set zeros
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (zeroRows[i] || zeroCols[j])
                    Matrix[i][j] = 0;
    }
};
