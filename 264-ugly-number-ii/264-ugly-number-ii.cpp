class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long> > pq;
        pq.push(1);
        int nth=0;
        long val;
        while(!pq.empty() && nth<n)
        {
            val=pq.top();
            pq.pop();
            while(!pq.empty() && val==pq.top()) 
                pq.pop();
            nth++;
            pq.push(2ll*val);
            pq.push(3ll*val);
            pq.push(5ll*val);
        }
        return val;
    }
};