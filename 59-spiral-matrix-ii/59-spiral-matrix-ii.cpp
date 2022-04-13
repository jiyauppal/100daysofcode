class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int num = 0;
        int top = 0, down = n-1, right = n-1, left = 0; // keeping 4 positions to fill the array accordingly!!
        while(top <= down && left <= right){
            for(int i = left; i <= right; i++)
                res[top][i] = ++num;
            top++;
            for(int i = top; i <= down; i++)
                res[i][right] = ++num;
            right--;
            for(int i = right; i >= left; i--)
                res[down][i] = ++num;
            down--;
            for(int i = down; i >= top; i--)
                res[i][left] = ++num;
            left++;
        }
        return res;
    }
};