class Solution {
public:
    int num_of_ones(int n)
    {
        int ans=0;
        while(n)
        {
            ans++;
            n=n&(n-1);
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0;i<=n;i++)
            ans.push_back(num_of_ones(i));
            
        return ans;
    }
};