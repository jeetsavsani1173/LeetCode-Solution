class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin=INT_MAX;
        int currAns=0;
        for(auto it:prices){
            currMin=min(currMin,it);
            currAns=max(currAns,it-currMin);
        }
        return currAns;
    }
};