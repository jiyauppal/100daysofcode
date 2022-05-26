class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int fromS = 1;
        int fromL = 1;
        
        for(int i= 0; i < n; i++){
            res[i] *= fromS;
            fromS *= nums[i];
            res[n-1-i] *= fromL;
            fromL *= nums[n-1-i];
        }
        return res;
    }
};