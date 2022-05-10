class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& output, int freq[]){
        if(output.size() == nums.size()){
            res.push_back(output);
            return;
        }
        for(int i = 0; i< nums.size(); i++){
            if(!freq[i]){
            output.push_back(nums[i]);
            freq[i] = 1;
            helper(nums, res, output, freq);
            freq[i] = 0;
            output.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        int freq[nums.size()];
        for(int i = 0; i < nums.size(); i++)
            freq[i]=0;
        helper(nums, res, output, freq);
        return res;
    }
};