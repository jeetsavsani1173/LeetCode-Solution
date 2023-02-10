//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<int,int> mp;
        for(auto it:s) mp[it]++;
        // cout<<mp['b']<<" "<<mp['a']<<" "<<mp['l']<<" "<<mp['n']<<endl;
        mp['l']/=2;
        mp['o']/=2;
        
        int ans=INT_MAX;
        ans=min(ans,mp['b']);
        ans=min(ans,mp['a']);
        ans=min(ans,mp['o']);
        ans=min(ans,mp['l']);
        ans=min(ans,mp['n']);
        // cout<<mp['b']<<" "<<mp['a']<<" "<<mp['l']<<" "<<mp['n']<<endl;
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends