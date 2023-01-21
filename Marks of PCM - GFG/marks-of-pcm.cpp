//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }else if(a[1]!=b[1]){
            return a[1]>b[1];
        }else{
            return a[2]<b[2];
        }
    }
    void customSort (int phy[], int chem[], int math[], int N)
    {
        vector<vector<int>> vpr;
        for(int i=0;i<N;i++)
            vpr.push_back({phy[i],chem[i],math[i]});
        
        sort(vpr.begin(),vpr.end(),cmp);
        
        for(int i=0;i<N;i++)
        {
            phy[i]=vpr[i][0];
            chem[i]=vpr[i][1];
            math[i]=vpr[i][2];
        }
    } 
};

//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends