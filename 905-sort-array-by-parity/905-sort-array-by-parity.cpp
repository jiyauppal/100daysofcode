class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0; 
        int j = 0;
        while(i != nums.size()){
            if(nums[i]%2 != 0){
                i++;
            }
            else{
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        return nums;
    }
};