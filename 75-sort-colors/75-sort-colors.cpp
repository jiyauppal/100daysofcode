class Solution {
public:
    void sortColors(vector<int>& a) {
        // int l = 0;
        // int r = nums.size()-1;
        // int mid = 0;
        // while(mid<=r){
        //     if(nums[mid] == 0){
        //         swap(nums[l], nums[mid]);
        //         l++;
        //         mid++;
        //     }
        //     else if(nums[mid] == 2){
        //         swap(nums[r], nums[mid]);
        //         r--;
        //     }
        //     else{
        //         mid++;}
        // }
        int n = a.size();
        int c0=0, c1=0, c2=0;
        for(int i = 0; i <= n-1; i++){
            if(a[i] == 0) c0++;
            if(a[i] == 1) c1++;
            if(a[i] == 2) c2++;
        }
        for(int i = 0; i < c0; i++)
        a[i] = 0;
        for(int i = c0; i < c1+c0; i++)
        a[i] = 1;
        for(int i = c1+c0; i < c2+c0+c1; i++)
        a[i] = 2;
    }
};