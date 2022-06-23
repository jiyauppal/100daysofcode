class Solution {
public:
    void combinations(int i, vector<string>& mp, vector<string>& res, string temp, string digits){
        if(i >= digits.size()) {res.push_back(temp); return;}
        int number = digits[i] - '0';
        string value = mp[number];
        for(int  j= 0; j < value.size(); j++){
            temp.push_back(value[j]);
            combinations(i+1,mp, res, temp, digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string temp;
        if(digits.length() == 0) return res;
        combinations(0, mp, res, temp, digits);  
        return res;
    }
};