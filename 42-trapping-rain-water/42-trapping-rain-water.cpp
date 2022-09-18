class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pre(n,0);
        vector<int> post(n,0);
        pre[0]=height[0];
        post[n-1]=height[n-1];
        
        for(int i=1;i<n;i++)
            pre[i]=max(pre[i-1],height[i]);
        
        for(int i=n-2;i>=0;i--)
            post[i]=max(post[i+1],height[i]);
        
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=(min(pre[i],post[i])-height[i]);
        return ans;
    }
};