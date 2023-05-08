//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        if(s.size()!=t.size()) return false;
        map<char,char> mp;

        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=t[i];
            }else{
                if(mp[s[i]]!=t[i]) return false;
            }
        }

        mp.clear();
        swap(s,t);

        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=t[i];
            }else{
                if(mp[s[i]]!=t[i]) return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends