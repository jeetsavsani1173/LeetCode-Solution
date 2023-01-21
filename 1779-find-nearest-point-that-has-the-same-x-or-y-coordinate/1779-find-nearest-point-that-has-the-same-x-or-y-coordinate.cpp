class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int dis=INT_MAX;
        int ans=-1;
        for(int i=0;i<points.size();i++)
        {
            if(x==points[i][0] || y==points[i][1])
            {
                if((abs(x-points[i][0])+abs(y-points[i][1]))<dis){
                    dis=(abs(x-points[i][0])+abs(y-points[i][1]));
                    ans=i;
                }
            }
        }
        return ans;
    }
};