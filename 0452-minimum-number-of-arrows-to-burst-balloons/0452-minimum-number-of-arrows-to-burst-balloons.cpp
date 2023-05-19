class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        
        long limit=LONG_MIN;
        int count=0;
        
        for(auto it:points){
            if(limit<it[0]){
                count++;
                limit=it[1];
            }
        }
        return count;
    }
};