//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int turn = (N+K-1)/K;
        
        if(turn%2==1){
            int right=(N-1)/(2*K);
            int rightEle=right*K;
            return N-rightEle;
        }else{
            int left=(N+K)/(2*K);
            int leftEle=left*K;
            return 1+leftEle;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends