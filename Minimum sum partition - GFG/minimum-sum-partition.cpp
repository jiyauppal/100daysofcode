// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    vector<int>SubsetSum(int a[],int sum,int n){
        vector<vector<bool>>ans(n+1,vector<bool>(sum+1));
        for(int i=0;i<n+1;i++){
            ans[i][0]=true;
        }
        for(int i=1;i<sum+1;i++){
            ans[0][i]=false;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(a[i-1]<=j)
                    ans[i][j]=((ans[i-1][j-a[i-1]])||(ans[i-1][j]));
                else
                    ans[i][j]=ans[i-1][j];
            }
        }
        
    vector<int>subset;
        for(int i=0;i<=sum/2;i++)
            if(ans[n][i]==true)
                subset.push_back(i);
            
return subset;
    }

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	   vector<int>an=SubsetSum(arr,sum,n);
	    
	   int mn=INT_MAX;
	  for(auto i:an)
	        mn=min(mn,sum-2*i);
	        
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