class Solution {
public:// Logic  : Binary Search on Answer Space..
    long check(vector<int> &piles,int k){
        long total_hours=0;
        for(auto it:piles){
            if(it%k==0){
                total_hours+=(1ll*it/k);
            }else{
                total_hours+=(1ll*it/k+1);
            }
        }
        return total_hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long  l=1,r=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=r){
            long mid=(r-l)/2+l;
            if(check(piles,mid)<=h){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};