class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> graphs(n+1,vector<bool>(n+1,false));
        vector<int> deg(n+1,0);
        for(auto it:roads){
            graphs[it[0]][it[1]]=true;
            graphs[it[1]][it[0]]=true;
            deg[it[0]]++;
            deg[it[1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(graphs[i][j]){
                    ans=max(ans,deg[i]+deg[j]-1);
                }else{
                    ans=max(ans,deg[i]+deg[j]);
                }
            }
        }
        return ans;
    }
};