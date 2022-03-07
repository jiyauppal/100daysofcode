class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        int n = digits.size();
        for(int i = n-1; i >= 0 && carry; i--){
            carry = (++digits[i] %= 10) == 0;
        }
        if(carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
//submitted by jiyauppal