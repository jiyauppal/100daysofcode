class Solution {
public:
void findCombinations(int idx, int target, vector<int> &curr, vector<int> &candidates, vector<vector<int>> &res) {
    if(idx == candidates.size()) return;
        if(target == 0){
            res.push_back(curr);
        return;
        }
    if(target < 0) return;
    if(candidates[idx] <= target){
        curr.push_back(candidates[idx]);
        findCombinations(idx, target-candidates[idx], curr, candidates, res);
        curr.pop_back();
    }
    findCombinations(idx+1, target, curr, candidates, res);
    }

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> curr;
    findCombinations(0, target, curr, candidates, res);
    return res;
}
};