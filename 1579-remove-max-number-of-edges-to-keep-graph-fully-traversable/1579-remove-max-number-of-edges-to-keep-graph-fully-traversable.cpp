class DisjointSet{
    vector<int> rank,parent,size;
    int count;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
        count=0;
    }

    // find Ultimate Parent with path compression..
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by Rank..
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u==ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by Size
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            count=size[ulp_v];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
            count=size[ulp_u];
        }
    }
    
    int getCount(){
        return count;
    }
};

class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet a(n);
        DisjointSet b(n);
        
        sort(edges.begin(),edges.end(),cmp);
        
        int ans=0;
        for(auto it:edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];
            if(type==3){
                bool flag1=true;
                if(a.findUPar(u)!=a.findUPar(v)){
                    a.unionBySize(u,v);
                    flag1=false;
                }
                
                bool flag2=true;
                if(b.findUPar(u)!=b.findUPar(v)){
                    b.unionBySize(u,v);
                    flag2=false;
                }
                
                if(flag1 && flag2){
                    ans++;
                }
                
            }else if(type==2){
                bool flag2=true;
                if(b.findUPar(u)!=b.findUPar(v)){
                    b.unionBySize(u,v);
                    flag2=false;
                }
                if(flag2){
                    ans++;
                }
            }else{
                bool flag1=true;
                if(a.findUPar(u)!=a.findUPar(v)){
                    a.unionBySize(u,v);
                    flag1=false;
                }
                
                if(flag1){
                    ans++;
                }
            }
        }
        
        if(a.getCount()==n && b.getCount()==n){
            return ans;
        }else{
            return -1;
        }
    }
};