class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval=intervals[0];
        
        for(auto it:intervals){
            // in different interval
            if(tempInterval[1]<it[0]){
                ans.push_back(tempInterval);
                tempInterval=it;
            }else{
                tempInterval[1]=max(tempInterval[1],it[1]);
            }
        }
        ans.push_back(tempInterval);
        return ans;
    }
};