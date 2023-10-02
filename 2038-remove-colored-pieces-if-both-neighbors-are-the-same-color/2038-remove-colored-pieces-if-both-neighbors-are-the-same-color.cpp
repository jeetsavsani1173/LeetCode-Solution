class Solution {
public:
    bool winnerOfGame(string colors) {
        int moveACount=0,moveBCount=0;
        char currC=colors[0];
        int cnt=1;
        
        for(int i=1;i<colors.size();i++){
            if(colors[i]==currC){
                cnt++;
            }else{
                if(cnt>=3){
                    if(currC=='A') moveACount+=(cnt-2);
                    else moveBCount+=(cnt-2);
                }
                currC=colors[i];
                cnt=1;
            }
        }
        if(cnt>=3){
            if(currC=='A') moveACount+=(cnt-2);
            else moveBCount+=(cnt-2);
        }
        
        
        return moveACount>moveBCount;
    }
};