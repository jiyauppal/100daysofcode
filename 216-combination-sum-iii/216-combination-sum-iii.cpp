class Solution {
public:
    void findcombinations(int idx, vector<vector<int>>& ans, int k, int target, vector<int>& output){
        if(target == 0 && k == 0){
            ans.push_back(output);
            return;
        }
        for(int i = idx; i <= 10-k && i <= target; ++i){
            output.push_back(i);
            findcombinations(i+1, ans, k-1, target-i, output);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        findcombinations(1, ans, k, n, output);
        return ans;
    }
};