class Solution {
public:
    static bool comp(pair<int,string> &a,pair<int,string> &b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto it:words) mp[it]++;
        vector<pair<int,string>> vpr;
        for(auto it:mp)
            vpr.push_back({it.second,it.first});
        sort(vpr.begin(),vpr.end(),comp);
        vector<string> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vpr[i].second);
        }
        return ans;
    }
};