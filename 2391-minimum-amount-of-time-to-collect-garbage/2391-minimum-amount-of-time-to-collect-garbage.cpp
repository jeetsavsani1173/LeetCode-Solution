class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        int n=garbage.size();
        for(auto it:garbage) ans+=it.size();
        
        vector<vector<int>> mat(3,vector<int>(garbage.size(),0));
        
        for(int i=0;i<n;i++)
        {
            string str=garbage[i];
            for(int j=0;j<str.size();j++)
            {
                if(str[j]=='M') mat[0][i]++;
                else if(str[j]=='P') mat[1][i]++;
                else mat[2][i]++;
            }
        }
        
        //index of M
        int idx_m=n-1;
        while(idx_m>0 && mat[0][idx_m]==0)
            idx_m--;
        
        int idx_p=n-1;
        while(idx_p>0 && mat[1][idx_p]==0)
            idx_p--;
        
        int idx_g=n-1;
        while(idx_g>0 && mat[2][idx_g]==0)
            idx_g--;
        
        for(int i=0;i<idx_m;i++)
            ans+=travel[i];
        
        for(int i=0;i<idx_p;i++)
            ans+=travel[i];
        
        for(int i=0;i<idx_g;i++)
            ans+=travel[i];
        
        return ans;
    }
};