class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {}; //declaring the DP table

        dp[0][0] =1; //intializing 0,0 element 1
        
        for(int i=1 ; i<=n; ++i){ 
            long long int cs = 0;  // to maintain a window the length min(i,j)
            for(int j =0; j<=k; ++j){
                cs+=dp[i-1][j]; 
                
                if(j>=i){
                    cs-=dp[i-1][j-i];
                }
            dp[i][j] = ((long long)dp[i][j] + cs)%1000000007;             
                
                
            }
        }
        return dp[n][k]; 
    }
};