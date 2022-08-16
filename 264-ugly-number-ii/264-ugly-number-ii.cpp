class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        int ptr2=1,ptr3=1,ptr5=1;
        
        for(int i=2;i<=n;i++)
        {
            int a=dp[ptr2]*2;
            int b=dp[ptr3]*3;
            int c=dp[ptr5]*5;
            
            int mn=min(a,min(b,c));
            
            if(mn==a){
                dp.push_back(dp[ptr2]*2);
            }else if(mn==b){
                dp.push_back(dp[ptr3]*3);
            }else{
                dp.push_back(dp[ptr5]*5);
            }
            
            if(mn==a) ptr2++;
            if(mn==b) ptr3++;
            if(mn==c) ptr5++;
        }
        
        return dp[n];
    }
};