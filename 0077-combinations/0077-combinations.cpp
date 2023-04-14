class Solution {
public:
    void find_combine(int i,int n,int k,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        else if(i==n)
            return;
        temp.push_back(i+1);
        find_combine(i+1,n,k,temp,ans);
        temp.pop_back();
        find_combine(i+1,n,k,temp,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        find_combine(0,n,k,temp,ans);
        return ans;
    }
};