class Solution {
public:
    int helper(int idx,vector<vector<int>>& offers,vector<int> &dp){
        if(idx==offers.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int low=idx+1,high=offers.size()-1;
        int newIndex=offers.size();

        while(low<=high){
            int mid=(high-low)/2+low;

            if(offers[idx][1]<offers[mid][0]){
                high=mid-1;
                newIndex=mid;
            }else{
                low=mid+1;
            }
        }

        int take=1+helper(newIndex,offers,dp);
        int nonTake=helper(idx+1,offers,dp);

        return dp[idx]=max(take,nonTake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int> dp(n+1,-1);
        return helper(0,pairs,dp);
    }
};