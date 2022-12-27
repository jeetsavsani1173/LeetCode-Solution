class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int> v;
        
        for(int i=0;i<n;i++)
            v.push_back(capacity[i]-rocks[i]);
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(v[i]>0 && v[i]<=additionalRocks)
            {
                additionalRocks-=v[i];
                v[i]=0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            if(v[i]==0)
                ans++;
        
        return ans;
    }
};