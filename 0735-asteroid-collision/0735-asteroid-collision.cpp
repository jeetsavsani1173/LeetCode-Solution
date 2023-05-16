class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        stk.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            if(asteroids[i]>=0){ // positive
                // if(!stk.empty() && stk.top()<0){ // negative
                //     // collision
                //     stk.push(asteroids[i]);
                //     while(stk.size()>=2){
                //         int tp1=stk.top();
                //         stk.pop();
                //         int tp2=stk.top();
                //         stk.pop();
                //         if((tp2<0 && tp1>0) || (tp1*tp2)>0){
                //             stk.push(tp2);
                //             stk.push(tp1);
                //             break;
                //         }else if(abs(tp1)>abs(tp2)){
                //             stk.push(tp1);
                //         }else if(abs(tp1)<abs(tp2)){
                //             stk.push(tp2);
                //         }
                //     }
                // }else{ // positive
                //     // push
                //     stk.push(asteroids[i]);
                // }
                stk.push(asteroids[i]);
            }else{ // negative
                if(!stk.empty() && stk.top()>=0){ // positive
                    // collision
                    stk.push(asteroids[i]);
                    while(stk.size()>=2){
                        int tp1=stk.top();
                        stk.pop();
                        int tp2=stk.top();
                        stk.pop();
                        if((tp2<0 && tp1>0) || (tp1*tp2)>0){
                            stk.push(tp2);
                            stk.push(tp1);
                            break;
                        }else if(abs(tp1)>abs(tp2)){
                            stk.push(tp1);
                        }else if(abs(tp1)<abs(tp2)){
                            stk.push(tp2);
                        }
                    }
                }else{ // negative
                    // push
                    stk.push(asteroids[i]);
                }
            }
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};