//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int n1=S.size(),n2=T.size();
        int j=0;
        for(int i=0;i<n2;){
            if(S[j]==T[i]){
                i++;
                j++;
            }
            else if((S[j]>='A' and S[j]<='Z') and (T[i]>='0' and T[i]<='9')){
               int cnt=0;
               while(i<n2 and (T[i]>='0' and T[i]<='9')){
                   cnt=cnt*10+(T[i]-'0');
                   i++;
               }
               j+=cnt;
               if(j>n1){
                   return 0;
               }
            }
            else{
                return 0;
            }
            
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends