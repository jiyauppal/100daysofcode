class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxPro = INT_MIN;
        int minPrice = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            minPrice = min(minPrice, nums[i]);
            maxPro = max(maxPro, nums[i] - minPrice);
        }
        return maxPro;
    }
};