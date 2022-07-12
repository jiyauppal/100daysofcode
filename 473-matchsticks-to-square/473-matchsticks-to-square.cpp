class Solution {
public:
    bool dfs(int idx, vector<int>& matchsticks, vector<int>& bucket, int bucketsize){
        if(idx == matchsticks.size()) 
            return true;
            //return bucket[0] == bucket[1] && bucket[1] == bucket[2] && bucket[2] == bucket[3] && bucket[3] == bucket[4];
        for(int i = 0; i < 4; i++){
            if(bucket[i] + matchsticks[idx] <= bucketsize){
                bucket[i] += matchsticks[idx];
                if(dfs(idx+1, matchsticks, bucket, bucketsize))
                    return true;
                bucket[i] -= matchsticks[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i : matchsticks){
            sum += i;
        }
        if(sum == 0 || sum % 4) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int> ());
        vector<int> bucket(4, 0);
        return dfs(0, matchsticks, bucket, sum/4);
    }
};