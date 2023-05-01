class Solution {
public:
    double average(vector<int>& salary) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        
        for(auto it:salary){
            mn=min(mn,it);
            mx=max(mx,it);
        }
        
        double sum=0.0;
        for(auto it:salary){
            if(it==mn || it==mx){
                continue;
            }else{
                sum+=it;
            }
        }
        
        return sum/(double)(salary.size()-2);
    }
};