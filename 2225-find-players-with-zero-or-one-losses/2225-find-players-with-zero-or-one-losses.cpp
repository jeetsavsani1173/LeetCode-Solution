class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int> temp1;
        map<int,int> mp;
        
        for(auto it:matches)
            mp[it[1]]++;
        
        for(auto it:mp)
            if(it.second==1)
                temp1.push_back(it.first);
        
        set<int> st; 
        for(auto it:matches)
            if(mp[it[0]]==0)
                st.insert(it[0]);
        
        vector<int> temp2;
        for(auto it:st)
            temp2.push_back(it);
        
        ans.push_back(temp2);
        ans.push_back(temp1);
        return ans;
    }
};