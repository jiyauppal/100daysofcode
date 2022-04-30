class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        int ans = 0;
            for(auto it : pre){
                int u = it[0];
                int v = it[1];
                graph[v].push_back(u);
            }
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        unordered_set<int> vis;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
            {
                q.push(i);
                ans+=1;
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto nb : graph[curr]){
                indegree[nb] -= 1;
                if(indegree[nb] == 0){
                q.push(nb);
                ans += 1;
              }
            }
        }
        if(ans == n) return true;
        
        return false;
    }
};