class Solution {
public:
    void neighours(vector<vector<int>>& image, int i, int j, int m, int n, int curr, int newColor){
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] == newColor || image[i][j] != curr)
            return;
        
        image[i][j] = newColor;
        neighours(image, i-1, j, m, n, curr, newColor);
        neighours(image, i+1, j, m, n, curr, newColor);
        neighours(image, i, j-1, m, n, curr, newColor);
        neighours(image, i, j+1, m, n, curr, newColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int curr = image[sr][sc];
        neighours(image, sr, sc, m, n, curr, newColor);
        return image;
    }
};