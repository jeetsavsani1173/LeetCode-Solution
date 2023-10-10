class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        vector<int>unique;
        for(int item:s){
            unique.push_back(item);
        }
        
        sort(unique.begin(),unique.end());
        
        int ans = INT_MAX;
        for(int i=0;i<unique.size();i++)
        {
            int start = unique[i];
            int last = start+n-1;
            
            vector<int>::iterator upper=upper_bound(unique.begin(),unique.end(),last);
            int len = upper- unique.begin();
            ans = min(ans,n-(len-i));
            
        }
       return ans;
    }
};