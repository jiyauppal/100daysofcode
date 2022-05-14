// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isPossible(int idx, int i, int color[], bool graph[101][101],int n){
    for(int k = 0; k < n; k++){
        if(k != i && graph[k][i] == 1 && color[k] == idx){
            return false;
        }
    }
    return true;
}
bool solve(int i, int color[], bool graph[101][101], int m, int n){
    if(i == n) return true;
    
    for(int idx = 1; idx <= m; idx++){
        if(isPossible(idx, i, color, graph, n)){
         color[i] = idx;
         if(solve(i+1, color, graph, m, n)) return true;
         color[i] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    int color[n] = {0};
    if(solve(0, color, graph, m, n)) return true;
    return false;
}


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends