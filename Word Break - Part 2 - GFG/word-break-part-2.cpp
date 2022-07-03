// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> ans;
    void helper(int curr_idx,vector<string> &dist,int n,string &s,string temp)
    {
        if(curr_idx>=s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto it:dist)
        {
            string first_str=it;
            string second_str=s.substr(curr_idx,first_str.size());
            if(first_str==second_str){
                string ans;
                if(temp.size()!=0) ans=temp+" "+first_str;
                else ans=first_str;
                helper(curr_idx+first_str.size(),dist,n,s,ans);
            }
        }
        return;
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        string temp="";
        helper(0,dict,n,s,temp);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends