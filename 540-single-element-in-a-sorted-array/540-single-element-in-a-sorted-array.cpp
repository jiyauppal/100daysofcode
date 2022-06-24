class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int ans = 0;
        while(i<j){
            if(nums[i] == nums[i+1])
                i = i+2;
            
            else  return nums[i];
             if(nums[j] == nums[j-1])
                j = j-2;
            
             else   return nums[j];
        }
        return nums[i];
    }
};