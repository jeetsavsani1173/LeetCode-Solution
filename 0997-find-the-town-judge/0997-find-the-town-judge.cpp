class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inde(n+1,0);
        vector<int> outde(n+1,0);
        
        for(auto it:trust)
        {
            inde[it[1]]++;
            outde[it[0]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(inde[i]==n-1 && outde[i]==0){
                return i;
            }
        }
        
        return -1;
    }
};