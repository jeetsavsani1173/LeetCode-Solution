class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows=34;
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> currAns;
            currAns.push_back(1);
            for(int j=1;j<ans[i-1].size();j++){
                currAns.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            currAns.push_back(1);
            ans.push_back(currAns);
        }
        return ans[rowIndex];
    }
};