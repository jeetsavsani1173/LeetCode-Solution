//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void helper(int idx,int n,string &temp,vector<bool> &vis,string &s,set<string> &st){
	        if(idx==n){
	            st.insert(temp);
	            return;
	        }
	        
	        for(int i=0;i<s.size();i++){
	            if(!vis[i]){
	                vis[i]=true;
    	            temp.push_back(s[i]);
    	            helper(idx+1,n,temp,vis,s,st);
    	            temp.pop_back();
    	            vis[i]=false;
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(),S.end());
		    set<string> ans;
		    vector<bool> vis(S.size(),false);
		    string temp;
		    helper(0,S.size(),temp,vis,S,ans);
		    vector<string> v;
		    for(auto it:ans) v.push_back(it);
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends