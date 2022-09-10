class Solution {
public:
    void combinations(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> &temp, int idx){
        if(idx == candidates.size()) {
            if(target == 0)
            ans.push_back(temp);
            return;
        }
        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            combinations(candidates, target-candidates[idx], ans, temp, idx);
            temp.pop_back();
        }
        combinations(candidates, target, ans, temp, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(candidates, target, ans, temp, 0);
        return ans;
    }
};