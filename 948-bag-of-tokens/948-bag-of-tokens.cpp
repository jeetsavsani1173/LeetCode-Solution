class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans=0;
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int score=0;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power-=tokens[i];
                i++;
            }else{
                if(score==0) return ans;
                score--;
                power+=tokens[j];
                j--;
            }
            
            ans=max(ans,score);
        }
        
        return ans;
    }
};