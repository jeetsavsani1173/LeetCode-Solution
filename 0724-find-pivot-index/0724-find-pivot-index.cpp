class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> suff(n+1,0);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i];
        }
        int leftSum=0;
        for(int i=0;i<n;i++){
            if(leftSum==suff[i+1]) return i;
            leftSum+=nums[i];
        }
        return -1;
    }
};