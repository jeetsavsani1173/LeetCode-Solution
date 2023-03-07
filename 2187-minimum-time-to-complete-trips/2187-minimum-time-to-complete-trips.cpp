class Solution {
public:
    bool isPossible(long long target,vector<int>& time,int totalTrips){
        long long temp_ans=0;
        for(auto it:time){
            temp_ans+=(target/it);
        }
        return temp_ans>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // if(time.size()==1) return totalTrips*time[0];
        long long l=1ll;
        long long r=1e14;
        // cout<<l<<" "<<r<<endl;
        long long ans=r;
        while(l<=r){
            long long mid=(r-l)/2+l;
            if(isPossible(mid,time,totalTrips)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
            // cout<<l<<" "<<r<<endl;
        }
        return ans;
    }
};