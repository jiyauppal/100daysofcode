class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B){
        vector<int> cA(7), cB(7), cS(7);
        int n = A.size();
        for(int i = 0; i < n; i++){
            int a = A[i];
            int b = B[i];
            cA[a]++;
            cB[b]++;
            if(a==b) cS[a]++;
        }
        int ans = n;
        for(int j = 1; j <= 6; j++){
            if(cA[j] + cB[j] - cS[j] == n){
                int minSwap = min(cA[j], cB[j]) - cS[j];
                ans = min(ans, minSwap);
            }
        }
        return (n == ans) ? -1 : ans;
    }
};