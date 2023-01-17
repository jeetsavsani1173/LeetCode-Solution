class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> pre(n+1,0);
        vector<int> suff(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
                pre[i]=(s[i]=='1');
            else
                pre[i]=pre[i-1]+(s[i]=='1');
        }
        
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                suff[i]=(s[i]=='0');
            }else{
                suff[i]=suff[i+1]+(s[i]=='0');
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            ans=min(ans,pre[i]+suff[i+1]);
        }
        
        ans=min(ans,suff[0]);
        ans=min(ans,pre[n-1]);
        return ans;
    }
};