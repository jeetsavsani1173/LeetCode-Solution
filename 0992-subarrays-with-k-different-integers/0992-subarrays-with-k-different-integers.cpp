class Solution {
public:
    int find(vector<int> &nums,int k){
        int left=0,count=0;
        map<int,int> mp;
        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int atmostk=find(nums,k);
        int atmostkOne=find(nums,k-1);
        return atmostk-atmostkOne;
    }
};