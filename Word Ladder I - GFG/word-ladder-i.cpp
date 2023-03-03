//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isEdge(string &a,string &b)
    {
        int cnt=0;
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i]) cnt++;
        return cnt==1;
    }
    int wordLadderLength(string src, string dest, vector<string>& wordList) {
        // Generate a Graph from input
        wordList.push_back(src);
        unordered_map<string,vector<string>> graph;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string a=wordList[i];
                string b=wordList[j];
                if(isEdge(a,b)){
                    graph[a].push_back(b);
                    graph[b].push_back(a);
                }
            }
        }
        
        // Apply BFS;
        queue<pair<string,int>> q;
        q.push({src,0});
        unordered_map<string,int> mp;
        
        while(!q.empty()){
            string node=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(mp[node]) continue;
            mp[node]++;
            if(node==dest) return 1+dis;
            for(auto it:graph[node]){
                if(!mp[it]){
                    q.push({it,dis+1});
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends