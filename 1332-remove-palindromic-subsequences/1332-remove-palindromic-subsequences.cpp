class Solution {
public:
    bool isPalindromic(string s){
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length()-i-1])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(isPalindromic(s)) return 1;
        else return 2;
    }
};