class Solution {
public:
    int maximum69Number (int num) {
        string nums = to_string(num);
        for(auto &i : nums){
            if(i == '6'){
                i = '9';
                break;
            }
        }
        return stoi(nums);
    }
};