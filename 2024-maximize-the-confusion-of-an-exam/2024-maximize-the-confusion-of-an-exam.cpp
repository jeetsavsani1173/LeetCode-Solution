class Solution {
public:
    bool isValid(int m,string &s,int k){
        int n=s.size();
        int trues=0,falses=0;
        for(int i=0;i<m;i++){
            trues+=(s[i]=='T');
            falses+=(s[i]=='F');
        }
        int total=min(trues,falses);
        for(int i=m;i<n;i++){
            total=min(total,min(trues,falses));
            
            trues+=(s[i]=='T');
            falses+=(s[i]=='F');
            
            trues-=(s[i-m]=='T');
            falses-=(s[i-m]=='F');
        }
        total=min(total,min(trues,falses));
        return total<=k;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left=1,right=answerKey.size();
        int ans=1;
        
        while(left<=right){
            int mid=(right-left)/2+left;
            
            if(isValid(mid,answerKey,k)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};