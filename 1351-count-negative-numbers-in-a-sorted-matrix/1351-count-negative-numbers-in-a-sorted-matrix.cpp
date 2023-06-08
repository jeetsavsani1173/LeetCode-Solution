class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        for(auto it:grid){
            for(auto it1:it) if(it1<0) cnt++;
        }
        return cnt;
    }
};