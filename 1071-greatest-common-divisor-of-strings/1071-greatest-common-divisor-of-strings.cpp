class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
                return (str1+ str2 == str2 + str1) ? str1.substr(0, gcd(str1.length(), str2.length())) : "";        
    }
};
/*
    if(str1.size() < str2.size()) return gcdOfStrings(str2, str1); //first string always should be greater than the second one
        else if(str2.empty()) return str1;
        else if(str1.find(str2) != 0) return ""; // prefix of both strings are same or not if not return empty string

        return gcdOfStrings(str1.substr(str2.length()), str2);    
*/