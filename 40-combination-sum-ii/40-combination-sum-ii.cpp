class Solution {
public:
    void findCombinations(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> &ds, int idx){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            findCombinations(candidates, target-candidates[i], ans, ds, i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombinations(candidates, target, ans, ds, 0);
        return ans;
    }
};