//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    unordered_set<string> st;
	    void helper(int i,int j,string &s,string &t,string &temp,vector<vector<int>> &dp){
	        if(i==0 || j==0){
	            reverse(temp.begin(),temp.end());
	            st.insert(temp);
	            reverse(temp.begin(),temp.end());
	            return;
	        }
	        if(s[i-1]==t[j-1]){
	            temp.push_back(s[i-1]);
	            helper(i-1,j-1,s,t,temp,dp);
	            temp.pop_back();
	        }else{
	            if(dp[i][j]==dp[i][j-1]) helper(i,j-1,s,t,temp,dp);
	            if(dp[i][j]==dp[i-1][j]) helper(i-1,j,s,t,temp,dp);
	        }
	    }
	    void solve(int i,int j,string s,string t,string ans,int length,vector<string>&res,
        map<string,int>&mp){
            if(length==0){
               reverse(ans.begin(),ans.end());
               if(mp.find(ans)==mp.end()){
    	           res.push_back(ans);
                   mp[ans]++;
               }
               return;
            }
            if(i==0 || j==0){
                return;
            }
            for(int row=i;row>0;row--){
    	        for(int col=j;col>0;col--){
                    if(s[row-1]==t[col-1]){
                        ans+=s[row-1];
                        solve(row-1,col-1,s,t,ans,length-1,res,mp);
                        ans.pop_back();
                    }
                }   
            }
        }
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int n=s.size(),m=t.size();
		    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		    
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=m;j++){
		            if(s[i-1]==t[j-1]){
		                dp[i][j]=1+dp[i-1][j-1];
		            }else{
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    
		    map<string,int>mp;
            vector<string>res;
            solve(n,m,s,t,"",dp[n][m],res,mp);
            sort(res.begin(),res.end());
            return res;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends