// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	 vector<int> subsetSum(int nums[], int r, int n){
        bool dp[n+1][r+1];
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
        for(int j = 0; j <= r/2 ; j++)
            if(dp[n][j] == true)
                res.push_back(j);
        
        return res;
    }
    int minDifference(int nums[], int n) {
        int r = 0;
        for(int i = 0; i < n; i++)
            r+=nums[i];
        vector<int> vec = subsetSum(nums, r, n);
        int mn = INT_MAX;
        for(auto i : vec){
            mn = min(mn, r-2*i);
        }
        return mn;
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