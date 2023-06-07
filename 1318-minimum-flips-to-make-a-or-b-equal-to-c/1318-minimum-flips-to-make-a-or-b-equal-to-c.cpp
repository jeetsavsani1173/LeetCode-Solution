class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0;i<31;i++){
            bool bitA=(1<<i)&a;
            bool bitB=(1<<i)&b;
            bool bitC=(1<<i)&c;
            if((bitA||bitB) != bitC){
                if(bitA && bitB){
                    cnt+=2;
                }else{
                    cnt++;
                }
            }
        }
        return cnt;
    }
};