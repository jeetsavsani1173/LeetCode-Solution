class Solution {
public:
    vector<int> find_sorted_order(int i,int j,vector<vector<int>>& mat)
    {
        int n=mat.size(),m=mat[0].size();
        vector<int> ans;
        while(i<n && j<m)
        {
            ans.push_back(mat[i][j]);
            i++;
            j++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    void place(int i,int j,vector<int>& ans,vector<vector<int>>& mat)
    {
        int n=mat.size(),m=mat[0].size();
        int idx=0;
        
        while(i<n && j<m)
        {
            mat[i][j]=ans[idx];
            i++;
            j++;
            idx++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        
        // for lower-diogonal
        int i=n-2,j=0;
        while(i>=0)
        {
            vector<int> arr=find_sorted_order(i,j,mat);
            place(i,j,arr,mat);
            i--;
        }
             
        // for upper-diogonal
        i=0,j=m-2;
        while(j>0){
            vector<int> arr=find_sorted_order(i,j,mat);
            place(i,j,arr,mat);
            j--;
        }
        return mat;
    }
};