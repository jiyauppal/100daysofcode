class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        int n = s.size();
        for(auto i : wordDict){
            dict.insert(i);
        }
        unordered_set<int> vis;
        queue<int> q({0});
        while(!q.empty()){
            int start = q.front();
            q.pop();
            if(vis.count(start)) continue; //already visited
            vis.insert(start); //else insert it into visited set
            string sub;
            for(int j = start; j < s.size(); j++)
                if(dict.count(sub+=s[j])){
                   q.push(j+1);
                    if(j+1 == n) return 1;
                }
        }
        return 0;
    }
};