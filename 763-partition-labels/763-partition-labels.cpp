class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int>mp;      
        vector<int>ans;                  
        int temp = 0;
        int temp2 = -1;
        for(int i = 0; i < s.length(); i++)
            mp[s[i]] = i;
            
        for(int i = 0; i < s.length(); i++){
            if(mp[s[i]] > temp){
                temp = mp[s[i]];
            }
            if(temp == i){
                ans.push_back(temp-temp2);
                temp2 = temp;
            }
        }
        return ans;
    }
};