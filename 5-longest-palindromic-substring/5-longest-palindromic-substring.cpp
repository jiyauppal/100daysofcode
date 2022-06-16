class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0; int maxLen = 1; //keep two start and maxLen pointers to return substr in results
        //for substring of length 1(as all are palindromic so)
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        //for substrings of size 2
        for(int i = 0; i < n; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
        //for substrings greater than equal size 3
        for(int k = 3; k <= n; k++) {//here k is size of substring
            for(int i = 0; i < n-k+1; i++){ //first index of substr
                int j = i+k-1; //last index of substr
                if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    if(k > maxLen){ //to find longest substring
                        maxLen = k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};