class Solution {
public:
    int bestClosingTime(string customers) {
        int ys=0,ns=0;
        for(auto it:customers){
            if(it=='Y') ys++;
            else ns++;
        }
        int mn=INT_MAX;
        int ans=-1;
        int newYs=0,newNs=0;
        for(int i=0;i<customers.size();i++){
            int newPenalty=newNs+(ys-newYs);
            if(newPenalty<mn){
                mn=newPenalty;
                ans=i;
            }
            if(customers[i]=='Y') newYs++;
            else newNs++;
        }
        
        int newPenalty=newNs+(ys-newYs);
        if(newPenalty<mn){
            mn=newPenalty;
            ans=customers.size();
        }
        return ans;
    }
};