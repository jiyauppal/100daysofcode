// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfsTravel(vector<vector<int>> &maze, int r, int c, int n, string currPath, vector<string> &paths){
        if(r<0 || r>=n || c<0 || c>=n || maze[r][c] == 0)
            return;
        
        if(r == n-1 && c == n-1){
            paths.push_back(currPath);
            return;
        }

        maze[r][c] = 0;
        dfsTravel(maze, r+1, c, n, currPath+"D", paths);
        dfsTravel(maze, r, c+1, n, currPath+"R", paths);
        dfsTravel(maze, r-1, c, n, currPath+"U", paths);
        dfsTravel(maze, r, c-1, n, currPath+"L", paths);
        maze[r][c] = 1;
    }

    vector<string> findPath(vector<vector<int>> &maze, int n){
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0)
            return {};
        vector<string> paths;
        dfsTravel(maze, 0, 0, n, "", paths);
        return paths;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends