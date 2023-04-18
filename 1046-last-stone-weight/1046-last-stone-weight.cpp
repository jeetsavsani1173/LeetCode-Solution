class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it:stones) pq.push(it);
        
        while(pq.size()>1){
            int mx1=pq.top();
            pq.pop();
            int mx2=pq.top();
            pq.pop();
            
            if(mx1!=mx2){
                pq.push(mx1-mx2);
            }
        }
        
        if(pq.size()==1) return pq.top();
        return 0;
    }
};