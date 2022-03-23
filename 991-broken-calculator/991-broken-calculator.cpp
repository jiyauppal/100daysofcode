class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        if(target == startValue) return 0;
        while(startValue != target){
        if(target%2==0 && target > startValue){
            target = target/2;
            count++;
        }
        else{
            count++;
            target++;
        }
        }
        
        return count;
    }
};