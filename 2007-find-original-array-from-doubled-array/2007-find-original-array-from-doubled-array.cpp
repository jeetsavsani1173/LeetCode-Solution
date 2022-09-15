class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> mp;
        
        for(auto it:changed) mp[it]++;
        
        vector<int> ans;
        int cnt0=mp[0];
        if(cnt0&1) cnt0--;
        cnt0/=2;
        while(cnt0--) ans.push_back(0);
        
        for(auto it:mp){
            if(it.first!=0 && it.second!=0 && mp.find(it.first*2)!=mp.end()){
                int times=min(it.second,mp[2*it.first]);
                for(int i=0;i<times;i++) ans.push_back(it.first);
                mp[it.first]-=times;
                mp[2*it.first]-=times;
            }
        }
        if(ans.size()*2==changed.size()) return ans;
        return {};
    }
};