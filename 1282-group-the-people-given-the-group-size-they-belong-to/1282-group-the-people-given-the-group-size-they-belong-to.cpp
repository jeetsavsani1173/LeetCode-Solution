class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> ans;
        
        for(auto it:mp){
            if(it.first!=it.second.size()){
                vector<int> v=it.second;
                int k=it.second.size()/it.first;
                int j=0;
                for(int i=0;i<k;i++){
                    int cnt=it.first;
                    vector<int> temp;
                    for(;cnt;j++,cnt--){
                        temp.push_back(it.second[j]);
                    }
                    ans.push_back(temp);
                }
            }else{
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};