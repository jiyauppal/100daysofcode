class Solution {
public:
    void allpaths(vector<vector<int>>&graph, int curr_node, vector<int>&path,vector<vector<int>>& res){
        path.push_back(curr_node);
        if(curr_node == graph.size()-1){
            res.push_back(path);
        }
        else for(auto it : graph[curr_node])
            allpaths(graph, it, path, res);
            path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        allpaths(graph, 0, path, res);
        return res;
    }
};
 