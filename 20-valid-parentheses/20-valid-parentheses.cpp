class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1) return false;
        stack<char> st;
        for(int i = 0; i < s.length();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] =='['){
                st.push(s[i]);
            }
            else{
                char ch = st.top();
                if(st.empty() || (ch == '(' && s[i] != ')') ||( ch == '{' && s[i] != '}')|| (ch == '[' && s[i] != ']')) return false;
                st.pop();
        }}
        if(st.empty())
            return true;
        else
            return false;
    }
};