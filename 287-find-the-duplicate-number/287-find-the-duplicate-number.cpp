class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> freq;
        int duplicate = 0;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        for(auto i : freq){
            if(i.second > 1){
                duplicate = i.first;
                break;
            }}
        return duplicate;
    }
};