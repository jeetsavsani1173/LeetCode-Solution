class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto it:s) mp[it]++;
        
        vector<pair<int,char>> vpr;
        for(auto it:mp) vpr.push_back({it.second,it.first});
        
        sort(vpr.begin(),vpr.end());
        reverse(vpr.begin(),vpr.end());
        
        int i=0;
        for(auto it:vpr){
            while(it.first--){
                s[i++]=it.second;
            }
        }
        
        return s;
    }
};