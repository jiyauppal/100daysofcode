class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        int start = 0;
        int end = n-1;
        while(start < end){
            if(nums[start] + nums[end] > limit) end--;
            else{
                cnt++;
                start++;
                end--;
            }
        }
        return n-cnt;
    }
};