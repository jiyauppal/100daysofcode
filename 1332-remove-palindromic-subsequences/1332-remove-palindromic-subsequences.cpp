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
        if(isPalindromic(s)) return 1; // if string is palindromic it will be deleted in 1 operation
        else return 2; //if the string is not palindromic there are several a and subsequences which can be deleted in 1 operation
    }
};