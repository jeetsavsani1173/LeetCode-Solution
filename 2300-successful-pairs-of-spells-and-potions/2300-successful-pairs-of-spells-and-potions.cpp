class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        
        vector<int> ans;
        
        for(int i=0;i<spells.size();i++)
        {
            long long target;
            if(success%(spells[i]*1ll)==0)
                target=success/(spells[i]*1ll);
            else
                target=1ll+success/(spells[i]*1ll);
            int idx=lower_bound(potions.begin(),potions.end(),target)-potions.begin();
            
            ans.push_back(potions.size()-idx);
        }
        return ans;
    }
};