class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(n<=3) return ans;
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>0 && j-1!=i && nums[j]==nums[j-1]) continue;
                
                long long int newTarget=target-(1ll)*nums[i]-(1ll)*nums[j];
                int l=j+1,r=n-1;
                while(l<r){
                    if((nums[l]+nums[r])==newTarget){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        int temp=nums[l];
                        while(l<n && nums[l]==temp) l++;
                        r--;
                    }else if((nums[l]+nums[r])<newTarget){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        
        return ans;
    }
};