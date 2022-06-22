class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int a = 1;
        int b = 1;
        for(int i = 0; i < nums.size(); i++){
            res[i] *= a;
            a *= nums[i];
            res[n-1-i] *= b;
            b *= nums[n-1-i];
        }
        return res;
    }
};
