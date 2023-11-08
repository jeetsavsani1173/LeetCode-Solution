class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xDistance = abs(sx - fx);
        int yDistance = abs(sy - fy);
        int minDist = min(xDistance, yDistance) + abs(yDistance - xDistance);
        if (minDist == 0) {
            return t != 1;
        }
        return t >= minDist;
    }
};