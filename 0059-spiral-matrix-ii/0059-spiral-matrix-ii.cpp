class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int minr=0;
        int minc=0;

        int maxr=n-1;
        int maxc=n-1;

        int tne=(maxr+1)*(maxc+1);
        int cnt=0;
        while(cnt<tne)
        {
            for(int j = minc; j <= maxc && cnt < tne; j++){
                ans[minr][j]=cnt+1;
                cnt++;
             }
             minr++;

            for(int i = minr; i <= maxr && cnt < tne; i++){
                ans[i][maxc]=cnt+1;
                cnt++;
             }
             maxc--;


             for(int j = maxc; j >= minc && cnt < tne; j--){
                 ans[maxr][j]=cnt+1;
                cnt++;
             }
             maxr--;

            for(int i = maxr; i >= minr && cnt < tne; i--){
                ans[i][minc]=cnt+1;
                cnt++;
             }
             minc++;
        }
        return ans;
    }
};