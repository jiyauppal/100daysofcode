class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto i : nums){
            int c = k - i;
            if(mp[c] > 0){ans++; mp[c]--;}
            else mp[i]++;
            
        }
        return ans;
    }
};