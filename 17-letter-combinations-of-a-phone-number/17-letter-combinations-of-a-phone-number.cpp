class Solution {
public:
    void combinationsLetter(string digits, vector<string>& ans, int index, string output, vector<string>& mapping){
        if(index >= digits.length()){ ans.push_back(output); return;} // base condition of recursion
        
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i = 0; i < value.length(); i++){
            output.push_back(value[i]);
            combinationsLetter(digits, ans, index+1, output, mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int index = 0;
        if(digits.length() == 0) return ans;
        string output;
        vector<string> mapping = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        combinationsLetter(digits, ans, index, output, mapping);
        return ans;
    }
};