class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > first)
                first = nums[i];
        }
        long second = LONG_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > second && nums[i] < first)
                second = nums[i];       
        }
        long third = LONG_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > third && nums[i] < second)
                third = nums[i];       
        }
        if(third == LONG_MIN) return first;
        return third;
    }
};