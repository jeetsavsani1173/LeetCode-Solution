class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> temp=intervals[0];
        
        for(auto it:intervals){
            if(temp[1]<it[0]){
                // start new interval
                ans.push_back(temp);
                temp=it;
            }else{
                // continue to the prev interval by update maximum of end
                temp[1]=max(temp[1],it[1]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};