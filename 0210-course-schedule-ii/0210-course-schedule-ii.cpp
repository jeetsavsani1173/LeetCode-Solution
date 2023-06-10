class Solution {
public:
    vector<int> graph[2005];
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        for(auto it:prerequisites){
            graph[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        
        vector<int> ans;
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty()){
            int tp=q.front();
            q.pop();
            
            for(auto child:graph[tp]){
                indeg[child]--;
                if(indeg[child]==0){
                    q.push(child);
                    ans.push_back(child);
                }
            }
        }
        
        if(ans.size()==numCourses) return ans;
        return {};
    }
};