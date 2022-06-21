class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int maxi = 0;
        int maxi1 = -1;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] > maxi)
                maxi = mp[s[i]];
            if(maxi == i){
                res.push_back(maxi - maxi1);
                maxi1 = maxi;
            }
        }
        return res;
    }
};