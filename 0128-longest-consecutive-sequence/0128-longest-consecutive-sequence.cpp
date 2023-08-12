class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ust;
        for(auto it:nums) ust.insert(it);
        
        int ans=0;
        
        for(auto it:ust){
            if(ust.find(it-1)!=ust.end()){
                continue;
            }else{
                int tempAns=1;
                int ele=it+1;
                while(ust.find(ele)!=ust.end()){
                    tempAns++;
                    ele++;
                }
                ans=max(ans,tempAns);
            }
        }
        return ans;
    }
};