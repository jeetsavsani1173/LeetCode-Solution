class Solution {
public:
    static bool comp(int &a,int &b)
    {
        return (a>b);
    }
    bool flag;
    bool helper(int idx,vector<int>& matchsticks,vector<int> &sides,long &sum)
    {
        if(idx==matchsticks.size()){
            return true;
        }
        for(int k=0;k<4;k++)
        {
            if(sides[k]+matchsticks[idx]<=(sum/4)){
                sides[k]+=matchsticks[idx];
                if(helper(idx+1,matchsticks,sides,sum)) return true;
                sides[k]-=matchsticks[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        long sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4ll!=0) return false;
        sort(matchsticks.begin(),matchsticks.end(),comp);
        
        vector<int> sides(4,0);
        flag=false;
        flag=helper(0,matchsticks,sides,sum);
        return flag;
    }
};