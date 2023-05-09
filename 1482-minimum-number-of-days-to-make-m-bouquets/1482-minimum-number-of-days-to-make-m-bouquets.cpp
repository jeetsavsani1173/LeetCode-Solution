class Solution {
public:
    int check(vector<int>& bloomDay,int days,int k){
        int totalBouquets=0;
        int count=0;
        
        for(auto it:bloomDay){
            if(it<=days){
                count++;
            }else{
                count=0;
            }
            if(count==k){
                totalBouquets++;
                count=0;
            }
        }
        return totalBouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(1ll*m*k>1ll*n) return -1;
        
        int l=1,r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=r){
            int mid=(r-l)/2+l;
            
            if(check(bloomDay,mid,k)>=m){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};