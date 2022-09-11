class Solution {
public:
    long M;
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.first==b.first) return a.second>b.second;
        return a.first>b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        M=1e9+7;
        vector<pair<int,int>> vpr;
        for(int i=0;i<n;i++)
            vpr.push_back({efficiency[i],speed[i]});
        
        sort(vpr.begin(),vpr.end(),comp);
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        long sum=0;
        long ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=vpr[i].second;
            pq.push(vpr[i].second);
            
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            
            ans=max(ans,((sum)*(vpr[i].first)));
        }
        return ans%M;
    }
};