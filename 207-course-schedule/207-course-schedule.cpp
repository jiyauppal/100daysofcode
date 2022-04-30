class Solution {
public:
    vector<vector<int>> createGraph(int numCourses, vector<vector<int>>& pre){
        vector<vector<int>> graph(numCourses);
        for(auto it : pre){
            int u = it[0];
            int v = it[1];
            graph[v].push_back(u);
        }
        return graph;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph = createGraph(numCourses, prerequisites);
        for(int i = 0; i < numCourses; i++)
            for(int it : graph[i])
                indegree[it]++;
            
        queue<int> q;
        int ans = 0;
        unordered_set<int> vis;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                ans += 1;
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(vis.find(curr)!=vis.end())
                continue;
            vis.insert(curr);
            for(int j : graph[curr]){
                indegree[j] -= 1;
                if(indegree[j] == 0){
                    q.push(j);
                    ans += 1;
                }
            }
        }
        if(numCourses == ans)
            return true;
        else
            return false;
    }
};