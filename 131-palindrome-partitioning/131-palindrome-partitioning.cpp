class Solution {
public:
    void partitioning(string s, int index, vector<vector<string>>& ans, vector<string>& path){
        if(index == s.size()){
            ans.push_back(path);
            return;
        } 
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                partitioning(s, i+1, ans, path);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
        if(s[start++] != s[end--])
            return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        partitioning(s, 0, ans, path);
        return ans;
    }
};