class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, vector<int>& color){
        if(color[i] == 0) color[i] = 1;
        
        for(auto child : graph[i]){
            if(color[child] == 0){
                color[child] = -color[i];
                if(!dfs(graph, child, color)) return false;
            }
            else if(color[child] == color[i])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for(int i = 0; i < n; i++){
            if(!dfs(graph, i, color))
                return false;
        }
    
        return true;
    }
};