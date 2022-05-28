class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        sort(nums.begin(), nums.end());
        for(i = 0; i < nums.size(); i++){
            if(nums[i] == i)
                continue;
            else
                return i;
        }
        return i;
    }
};