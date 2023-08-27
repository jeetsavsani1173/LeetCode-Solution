class Solution {
public:
    int helper(int idx,int next_move,vector<int> &stones,map<int,int> &mp,map<pair<int,int>,int> &dp){
        if(idx==stones.size()-1) return true;
        if(dp.find({idx,next_move})!=dp.end()) return dp[{idx,next_move}];
        bool flag1=false,flag2=false,flag3=false;
        // k-1 move
        if((next_move-1)>0 && mp.find(stones[idx]+(next_move-1))!=mp.end()){
            flag1=helper(mp[stones[idx]+(next_move-1)],next_move-1,stones,mp,dp);
        }
        
        // k move
        if((next_move)>0 && mp.find(stones[idx]+(next_move))!=mp.end()){
            flag2=helper(mp[stones[idx]+(next_move)],next_move,stones,mp,dp);
        }
        
        // k+1 move
        if((next_move+1)>0 && mp.find(stones[idx]+(next_move+1))!=mp.end()){
            flag3=helper(mp[stones[idx]+(next_move+1)],next_move+1,stones,mp,dp);
        }
        
        return dp[{idx,next_move}]=flag1 || flag2 || flag3;
    }
    bool canCross(vector<int>& stones) {
        map<int,int> mp;
        
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        map<pair<int,int>,int> dp;
        return helper(0,0,stones,mp,dp);
    }
};