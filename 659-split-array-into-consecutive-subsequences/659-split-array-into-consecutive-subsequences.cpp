class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, std::greater<int>>> pqList;
        
        int count=0;
        
        for(auto it:nums){
            
            if(!pqList[it-1].empty()){
                int size=pqList[it-1].top();
                pqList[it-1].pop();
                pqList[it].push(++size);
                if(size==3) count--; 
            }else{
                pqList[it].push(1);
                count++;
            }
        }
        
        return count==0;
    }
};