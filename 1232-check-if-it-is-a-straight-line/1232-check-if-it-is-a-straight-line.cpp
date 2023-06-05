class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& points) {
        int x = points[1][0] - points[0][0];
        int y = points[1][1] - points[0][1];     
        int n=points.size();
        for(int i=0;i<n;i++){
            if(y*(points[i][0]-points[0][0])!=x*(points[i][1]-points[0][1]))
                return false;
        }
        return true;
    }
};