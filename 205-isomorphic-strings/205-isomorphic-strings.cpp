class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_t;
        for(int i = 0; i < s.size(); i++){
            if(mp_s[s[i]] != mp_t[t[i]])
                return false;
        else{
            mp_s[s[i]] = i+1;
            mp_t[t[i]] = i+1;
        }}
        return true;
    }
};