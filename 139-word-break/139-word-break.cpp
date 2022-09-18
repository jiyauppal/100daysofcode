class Solution {
public:
    bool solve(string s, set<string>& dict, int i, vector<char>& dp) {
        if(i == s.size()) return true;
        if(dp[i]!=-1) return dp[i];
        string sub;
        
        for(int j = i; j < s.size(); j++){
            if(dict.count(sub+=s[j]) && solve(s, dict, j+1, dp))
                return dp[i] = 1;;
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        vector<char> dp(s.size(), -1);
        for(auto i : wordDict){
            dict.insert(i);
        }
        return solve(s, dict, 0, dp);
    }
};