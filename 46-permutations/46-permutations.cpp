class Solution {
public:
    void permutations(vector<int>& nums, vector<vector<int>>& results, int i){
        if(i == nums.size()){
            results.push_back(nums);
            return;
        }
        for(int ind = i; ind < nums.size(); ind++){
            swap(nums[i], nums[ind]);
            permutations(nums, results, i+1);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        permutations(nums, results, 0);
        return results;
    }
};