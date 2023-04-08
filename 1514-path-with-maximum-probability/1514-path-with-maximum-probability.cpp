class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> graph[n+1];
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<double,int>> pq; // <prob,node>
        pq.push({1.00000,start});
        vector<bool> vis(n+1,false);
        while(!pq.empty()){
            pair<double,int> tp=pq.top();
            pq.pop();
            
            if(tp.second==end) return tp.first;
            if(vis[tp.second]==true) continue;
            vis[tp.second]=true;
            
            for(auto nbr:graph[tp.second]){
                pq.push({tp.first*nbr.second,nbr.first});
            }
        }
        
        return 0;
    }
};