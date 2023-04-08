class Solution {
public:
    class Compare {
    public:
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[2]>=b[2];
        }
    };
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n=0;
        for(auto it:routes) for(auto it1:it) n=max(n,it1);
        vector<vector<vector<int>>> graph(n+1);
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                int src=routes[i][j];
                int dest=routes[i][(j+1)%routes[i].size()];
                
                graph[src].push_back({dest,i});
                graph[dest].push_back({src,i});
            }
        }
        
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        pq.push({source,(int)routes.size(),0});
        
        vector<vector<int>> vis(n+1,vector<int>(routes.size()+1,-1));
        
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            int stop=tp[0];
            int color=tp[1];
            int changes=tp[2];
            
            if(stop==target) return changes;
            
            if(vis[stop][color]!=-1) continue;
            vis[stop][color]=changes;
            
            for(auto nbr:graph[stop]){
                if(color==nbr[1]){
                    pq.push({nbr[0],nbr[1],changes});
                }else{
                    pq.push({nbr[0],nbr[1],changes+1});
                }
            }
        }
        return -1;
    }
};