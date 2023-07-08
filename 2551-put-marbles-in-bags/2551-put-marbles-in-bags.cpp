class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<long long> addjSum;
        for(int i=1;i<n;i++) addjSum.push_back(1ll*(weights[i]+weights[i-1]));
        
        sort(addjSum.begin(),addjSum.end());
        
        long long mnSum=1ll*(weights[0]+weights[n-1]);
        long long mxSum=1ll*(weights[0]+weights[n-1]);
        
        for(int i=0;i<(k-1) && i<addjSum.size();i++){
            mnSum+=addjSum[i];
        }
        k--;
        for(int i=addjSum.size()-1;i>=0 && k--;i--){
            mxSum+=addjSum[i];
        }
        // for(auto it:addjSum) cout<<it<<" ";
        // cout<<endl;
        // cout<<mxSum<<" "<<mnSum<<endl;
        return (mxSum-mnSum);
    }
};