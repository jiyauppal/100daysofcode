class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", n, 0);
        return res;
    }
    void generate(vector<string> &res, string str,int n,int m)
    {
        if(n == 0 && m == 0){
            res.push_back(str);
            return;
            }
        if(m>0) generate(res, str+")", n, m-1);
           if(n>0) generate(res, str+"(", n-1, m+1); 
    }
};
//n = number of "(" that had not put into the string
//m = number of "(" - ")" int the string