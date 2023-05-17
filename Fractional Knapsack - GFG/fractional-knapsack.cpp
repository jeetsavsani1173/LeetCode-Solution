//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        return (((double)a.first/(double)a.second)>((double)b.first/(double)b.second));
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<int,int>> vpr;
        for(int i=0;i<n;i++)
            vpr.push_back({arr[i].value,arr[i].weight});
            
        sort(vpr.begin(),vpr.end(),cmp);
        
        // for(auto it:vpr)
        //     cout<<it.first<<" "<<it.second<<endl;
        double ans=0.0;
        
        for(int i=0;i<n;i++)
        {
            ans+=(min(W,vpr[i].second)*(vpr[i].first/(double)vpr[i].second));
            W-=min(W,vpr[i].second);
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends