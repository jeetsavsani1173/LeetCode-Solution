class Solution {
public:
    vector<int> graph[2005];
    vector<int> bfs(vector<vector<int>>& prerequisites,int n)
    {
        vector<int> indeg(n,0);
        for(auto it:prerequisites)
        {
            indeg[it[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indeg[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it:graph[node])
            {
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        
        if(ans.size()==n) return ans;
        return {};
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto it:prerequisites)
            graph[it[1]].push_back(it[0]);
        
        // bfs
        vector<int> ans= bfs(prerequisites,numCourses);
        return ans.size()==numCourses?true:false;
    }
};