class Solution {
public:
    bool isPalindromic(string s, int i, int j){
        while(i <= j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
    void palindromicPartitions(string s, vector<string>& ds, vector<vector<string>>& result, int i){
        if(i == s.size()){
            result.push_back(ds);
            return;
        }
        for(int idx = i; idx < s.size(); idx++){
            if(isPalindromic(s, i, idx)){
                ds.push_back(s.substr(i, idx-i+1));
                palindromicPartitions(s, ds, result, idx+1);
                ds.pop_back();
            }}
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> result;
        palindromicPartitions(s, ds, result, 0);
        return result;
    }
};