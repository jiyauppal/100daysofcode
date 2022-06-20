class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(string& word : words)
            reverse(word.begin(), word.end());
        sort(words.begin(), words.end());
        int n = words.size();
        int ans = 0; 
        int S;
        string str = words[0];
        for(int i = 0; i < n; i++){
            S = str.size();
            if(words[i].compare(0, S, str))
                ans += 1+S;
            str = words[i];
        }
        ans += str.size()+1;
        return ans;
    }
};