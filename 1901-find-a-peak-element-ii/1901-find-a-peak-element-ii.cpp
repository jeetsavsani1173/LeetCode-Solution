class Solution {
public:
    int find_max(vector<int> &arr){
        int mxIdx=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>arr[mxIdx])
                mxIdx=i;
        }
        return mxIdx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int startRow=0,endRow=n-1;
        
        while(startRow<=endRow){
            int midRow=(endRow-startRow)/2+startRow;
            
            int rowMaxIdx=find_max(mat[midRow]);
            
            int up=(midRow>0)?(mat[midRow-1][rowMaxIdx]):(-1);
            int down=(midRow<n-1)?(mat[midRow+1][rowMaxIdx]):(-1);
            
            if(up<mat[midRow][rowMaxIdx] && mat[midRow][rowMaxIdx]>down){
                return {midRow,rowMaxIdx};
            }else if(up>mat[midRow][rowMaxIdx]){
                endRow=midRow-1;
            }else{
                startRow=midRow+1;
            }
        }
        return {0,0};
    }
};