class Solution {
public:
    bool isValid(int speed,vector<int>& dist, double hour){
        double currH=0.0;
        for(int i=0;i<dist.size();i++){
            if(dist[i]%speed==0){
                currH+=(dist[i]/speed);
            }else{
                if(i==(dist.size()-1)){
                    currH+=((double)dist[i]/speed);
                }else{
                    currH+=(1+dist[i]/speed);
                }
            }
        }
        return currH<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int N = dist.size();
        if (hour <= (double)(N - 1))
            return -1;
        int ans=-1;
        int l=1,r=1e7;
        
        while(l<r){
            int mid=(r-l)/2+l;
            
            if(isValid(mid,dist,hour)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return r;
    }
};