class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        
        map<int,int> mp;
        for(auto it:hand) mp[it]++;
        
        int ans=0;
        
        while(mp.size()>0){
            int curr=mp.begin()->first;
            for(int i=curr;i<curr+groupSize;i++){
                if(mp[i]>0){
                    mp[i]--;
                    if(mp[i]==0) mp.erase(i);
                }else{
                    return false;
                }
            }
            ans++;
        }
        return ans;
    }
};