class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);
        vis[0]=true;
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            for(int size=0;size<sz;size++){
                int index=q.front();
                q.pop();
                if(index==(n-1)) return level;
                vector<int> &temp=mp[arr[index]];
                temp.push_back(index-1);
                temp.push_back(index+1);
                for(auto it:temp){
                    if(it>=0 && it<n && !vis[it]){
                        vis[it]=true;
                        q.push(it);
                    }
                }
                temp.clear();
            }
            level++;
        }
        return 0;
    }
};