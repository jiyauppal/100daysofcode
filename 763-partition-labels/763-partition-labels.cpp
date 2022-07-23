class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]] = i;
        }
        vector<int> ans;
        for(int i = 0; i < s.length(); i++){
            int start = i;
            int end = mp[s[start]];
            while(start <= end){
                int e = mp[s[start]];
                end = max(end, e);
                start++;
            }
            ans.push_back(end-i+1);
            i = end;
        }
        return ans;
    }
};