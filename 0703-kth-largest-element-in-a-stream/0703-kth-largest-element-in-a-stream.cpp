class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int target;
    KthLargest(int k, vector<int>& nums) {
        target=k;
        for(auto it:nums){
            if(pq.size()<k){
                pq.push(it);
            }else{
                if(pq.top()<it){
                    pq.pop();
                    pq.push(it);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<target){
            pq.push(val);
        }else{
            if(pq.top()<val){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */