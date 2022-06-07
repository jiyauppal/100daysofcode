// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    int minimumd(int range, int r, int c, vector<vector<bool>>& dp){
      for(int i = c-1; i >=0; i--){
          if(dp[r-1][i] == 1){
              int subset_sum = i;
              return range-2*(subset_sum);
          }
      }
    }
	 int subsetSum(int nums[], int r, int n){
        vector<vector<bool>> dp(n+1, vector<bool> (r+1));
        vector<int> res;
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < r+1; j++){
                if(i==0 && j == 0) dp[i][j] = true;
                else if(j==0) dp[i][j] = true;
                else if(i==0) dp[i][j] = false;
                else if(j >= nums[i-1])
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
       return minimumd(r, n+1, (r/2)+1, dp);
    }
    int minDifference(int nums[], int n) {
        int r = 0;
        for(int i = 0; i < n; i++)
            r+=nums[i];
        return subsetSum(nums, r, n);
    }
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends