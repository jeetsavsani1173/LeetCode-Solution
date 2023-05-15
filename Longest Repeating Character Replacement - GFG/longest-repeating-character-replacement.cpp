//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        for(auto ch='A';ch<='Z';++ch){
            int left=0;
            int count=0;
            for(int right=0;right<n;right++){
                if(s[right]!=ch) count++;
                while(count>k){
                    if(s[left]!=ch) count--;
                    left++;
                }
                ans=max(ans,right-left+1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends