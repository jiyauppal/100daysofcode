class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=  nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(mp[nums[i]] > 1){
                mp[nums[i]]--;
                ans.push_back(nums[i]);
            } 
        }
        return ans;
    }
};
/*
    vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[nums[i]%n] = nums[nums[i]%n] + n; //if any element os repeating n will be added to its index multiple times and makes it more than double
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 2*n)
                res.push_back(i);
        }
        return res;
        */