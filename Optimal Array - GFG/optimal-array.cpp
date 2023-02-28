//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        vector<int> ans;
        int s1=0,s2=0;
        for(int i=0;i<(n+1)/2;i++){
            s1+=a[i];
            if(2*i<n){
                s2+=a[2*i];
                int curr_ans=((i+1)*a[i]-s1)+(s2-s1)-i*a[i];
                ans.push_back(curr_ans);
            }
            if(2*i+1<n){
                s2+=a[2*i+1];
                int curr_ans=((i+1)*a[i]-s1)+(s2-s1)-(i+1)*a[i];
                ans.push_back(curr_ans);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends