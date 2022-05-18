class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<int> dummy1(row, -1), dummy2(column, -1);
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(matrix[i][j] == 0)
                {
                    dummy1[i] = 0;
                    dummy2[j] = 0;
                }
        }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(dummy1[i] == 0 || dummy2[j] == 0)
                matrix[i][j] = 0;
            }
        }
    }
};