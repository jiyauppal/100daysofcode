class Solution {
public:
    void dfs(string start, string end, double& val, map<string, int>& visited, bool& found, map<string, double>& mp, map<string, vector<string>> &graph){
        visited[start] = 1;
        
        if(found == true) return;
        for(auto child: graph[start]){
            if(visited[child] != 1){
                val *= mp[start + "->" + child];
                if(end == child){
                    found = true;
                    return;
                }
                dfs(child, end, val, visited, found, mp, graph);
                if(found == true)
                    return;
                else{
                    val /= mp[start + "->" + child];
                }
            }
        }
    
    }  
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, double>mp;  //map to represent a directed graph
        map<string, vector<string>> graph; 
        vector<double> ans;
        
        int n = equations.size();
        int m = queries.size();
         // settle values in both the maps
        for(int i = 0; i < n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            mp[u + "->" + v] = values[i];
            mp[v + "->" + u] = 1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //traverse queries for output
        for(int j = 0; j < m; j++){
            string start = queries[j][0];
            string end = queries[j][1];
            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){
                ans.push_back(-1);
            }
            else{
                double val = 1;
                map<string, int> visited;
                bool found = false;
                if(start == end){
                    found = true;
                }
                else
                    dfs(start, end, val, visited, found, mp, graph);
                if(found == true){
                    ans.push_back(val);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};