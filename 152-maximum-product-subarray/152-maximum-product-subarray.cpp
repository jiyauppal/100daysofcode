class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = INT_MIN;
        int minpro = 1;
        int maxpro = 1;
        for(int n : nums){
            if(n <= 0){
                swap(minpro, maxpro);
            }
            minpro = min(minpro*n, n);
            maxpro = max(maxpro*n, n);
            res= max(res, maxpro);
        }
        return res;
    }
};