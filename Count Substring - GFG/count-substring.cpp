//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  // try to break Rule
    // Answer will be a = total subarray - (subarray which does't containes all element alteast one time..)
    int findNotP(string s){
        int left=0;
        int ans=0;
        int cntA=0,cntB=0,cntC=0;
        for(int right=0;right<s.size();right++){
            if(s[right]=='a') cntA++;
            if(s[right]=='b') cntB++;
            if(s[right]=='c') cntC++;
            
            // break Rule -> make any one char count to zero
            while(cntA!=0 && cntB!=0 && cntC!=0){
                if(s[left]=='a') cntA--;
                if(s[left]=='b') cntB--;
                if(s[left]=='c') cntC--;
                
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
    int countSubstring(string s) {
        int n=s.size();
        return 1ll*n*(n+1)/2ll - findNotP(s);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends