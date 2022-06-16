class Solution {
public:
    string solve(string& s, int i, int j){
        int n = s.size();
        while(i>=0 && j <n){
            if(s[i] != s[j]) break;
            i--;
            j++;
        }
        return s.substr(i+1, j-1-i);
    }
    void maxi(string& fin, string& res, int& maxLen){
        if(fin.size()>maxLen){
            res = fin;
            maxLen = fin.size();
        }
    }
    string longestPalindrome(string s) {
        string res;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            string odd = solve(s, i, i);
            maxi(odd,res,maxLen);
            string even = solve(s, i, i+1);
            maxi(even,res,maxLen);
        }
        return res;
    }
};