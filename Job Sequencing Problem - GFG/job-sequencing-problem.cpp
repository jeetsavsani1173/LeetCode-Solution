//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(pair<int,int> &a,pair<int,int> &b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>> vpr;
        for(int i=0;i<n;i++){
            vpr.push_back({arr[i].profit,arr[i].dead});
        }
        sort(vpr.begin(),vpr.end(),comp);
        int profit=0,jobs=0;
        int mxDead=0;
        for(auto it:vpr) mxDead=max(mxDead,it.second);
        vector<int> days(mxDead,-1);
        for(int i=0;i<n;i++){
            int idx=vpr[i].second-1;
            while(idx>=0 && days[idx]!=-1) idx--;
            
            if(idx!=-1){
                days[idx]=i;
                jobs++;
                profit+=vpr[i].first;
            }
        }
        return {jobs,profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends