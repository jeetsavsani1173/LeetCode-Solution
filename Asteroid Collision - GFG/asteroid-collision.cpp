//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> stk;
        stk.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            if(asteroids[i]>=0){ // positive
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends