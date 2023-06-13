class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans;
        for(int col=0;col<n;col++){
            for(int row=0;row<n;row++){
                bool flag=true;
                int i=0,j=0;
                while(i<n){
                    if(grid[row][j]!=grid[i][col])
                        flag=false;
                    if(!flag) break;
                    i++;
                    j++;
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};