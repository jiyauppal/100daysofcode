class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1; 
        int cA = 0, cB = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0 && (s[i] == '#' || cA >0)){
                if(s[i--] == '#')
                    cA++;
                else
                    cA--;
            }
            while(j >= 0 && (t[j] == '#' || cB >0)){
                if(t[j--] == '#')
                    cB++;
                else
                    cB--;
            }
            if(i < 0 || j < 0) return i == j;
            if(s[i--] != t[j--]) return false;
            
        }
         return i==j;   
    }
};