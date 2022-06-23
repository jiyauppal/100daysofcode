class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, 0);
        map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c){
                mp[c].push_back(i);
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] != c){
             int ans = INT_MAX;
            for(auto &idx : mp[c])
            ans = min(ans, abs(i-idx));
            res[i] = ans;
            }
        }
        return res;
    }
};