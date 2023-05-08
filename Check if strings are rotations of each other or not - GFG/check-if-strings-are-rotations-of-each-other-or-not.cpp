//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool isValid(string &s,string &t,int j){
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[j]) return false;
            j=(j+1)%t.size();
        }
        return true;
    }
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s,string goal)
    {
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<goal.size();i++){
            if(s[0]==goal[i]){
                if(isValid(s,goal,i)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends