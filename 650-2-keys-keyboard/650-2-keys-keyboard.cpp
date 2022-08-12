class Solution {
public:
    long helper(long screen,long buffer,int n,vector<vector<int>> &dp)
    {
        if(screen==n) return 0;
        if(screen>n || buffer>n) return INT_MAX;
        long copyPaste=2+helper(2*screen,screen,n,dp);
        long paste=1+helper(screen+buffer,buffer,n,dp);
        
        return min(copyPaste,paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(2*n+1,vector<int>(2*n+1,-1));
        
        return 1ll+helper(1,1,n,dp);
    }
};