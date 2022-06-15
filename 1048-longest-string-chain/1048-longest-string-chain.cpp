class Solution {
public:
    bool isValid(string& a, string& b){
        if(a.size() != b.size() + 1)
			return false;
		int i = 0, j = 0;
		while(i < a.size()) {
			if(a[i] == b[j]) 
				i++, j++;
			else 
				i++;
		}
		if(i == a.size() && j == b.size())
			return true;
		return false;
    }
    
   static bool comp(string &x, string &y){
	return x.size() < y.size();
}
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int cnt = INT_MIN;
        sort(words.begin(), words.end(), comp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isValid(words[i], words[j]) && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
            cnt = max(cnt, dp[i]);
        }
        return cnt;
    }
};