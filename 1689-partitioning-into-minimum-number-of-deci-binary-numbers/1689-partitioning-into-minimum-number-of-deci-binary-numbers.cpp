class Solution {
public:
    int minPartitions(string n) {
        int mx=INT_MIN;
        for(auto &it:n)
        {
            mx=max(mx,(int)it-'0');
        }
        return mx;
    }
};