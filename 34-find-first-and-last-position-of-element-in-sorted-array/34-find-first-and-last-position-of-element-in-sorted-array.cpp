class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // two binary search - one to find the left end of the range and one to find the right end of the range
        return {search(nums, target, true), search(nums, target, false)};
    }
    
    int search(vector<int>& nums, int target, bool search_left) {
        int ans = -1; // not found
        // modified binary search
        int lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid]) {
                // we found the target but we need to find the left start and right end with the same value
                // save result first, and keep trying search left with mid - 1 or right with mid + 1
                ans = mid;
                if (search_left) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else if (target > nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans; // either -1 or left/right end
    }
};