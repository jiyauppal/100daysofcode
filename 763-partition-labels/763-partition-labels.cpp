class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26, 0);
        for(int i = 0; i < s.size(); i++){
            mp[s[i] - 'a'] = i;
        }
        vector<int> ans;
        for(int i = 0; i < s.length(); i++){
            int start = i;
            int end = mp[s[start] - 'a'];
            while(start <= end){
                int e = mp[s[start] - 'a'];
                end = max(end, e);
                start++;
            }
            ans.push_back(end-i+1);
            i = end;
        }
        return ans;
    }
};