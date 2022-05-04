class Solution {
public:
    void findCombinations(int idx, vector<int>& curr, vector<vector<int>>& res, vector<int>& candidates, int target ){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(int i = idx; i < candidates.size();i++){
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            curr.push_back(candidates[i]);
            findCombinations(i+1, curr, res, candidates, target-candidates[i]);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        findCombinations(0, curr, res, candidates, target);
        return res;
    }
};