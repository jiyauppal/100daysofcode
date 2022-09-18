class Solution {
public:
//     bool solve(string s, set<string>& dict, int i, vector<char>& dp) {
//         if(i == s.size()) return true;
//         int n = s.size();
//         if(dp[i]!=-1) return dp[i];
//         string sub;
        
//         for(int j = i; j < s.size(); j++){
//             if(dict.count(sub+=s[j]) && solve(s, dict, j+1, dp))
//                 return dp[i] = 1;;
//         }
//         return dp[n];
//     }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(auto i : wordDict){
            dict.insert(i);
        }
        vector<bool> dp(s.size()+1, false);
        int n = s.size();
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >=0; j--){
                if(dp[j]){
                    string sub = s.substr(j, i-j);
                    if(dict.find(sub) != dict.end()){
                    dp[i] = true;
                    break;
                }}}
            }
        return dp[n];
    }
};