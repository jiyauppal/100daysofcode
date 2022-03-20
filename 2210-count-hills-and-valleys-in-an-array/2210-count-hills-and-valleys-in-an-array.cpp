class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), l = nums[0], i = 1, j = 1, ans = 0;
        while (i < n - 1)
        {
            j = i + 1;
            while (j < n && nums[j] == nums[i])
                j++;
            if (j == n)
                break;
            int r = nums[j];
            if (l > nums[i] && r > nums[i] || l < nums[i] && r < nums[i])
                ans += 1;
            l = nums[i];
            i = j;
        }
        return ans;
    }
};