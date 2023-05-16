//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        vector<int> pre(n,0);
        vector<int> post(n,0);
        pre[0]=height[0];
        post[n-1]=height[n-1];
        
        for(int i=1;i<n;i++)
            pre[i]=max(pre[i-1],height[i]);
        
        for(int i=n-2;i>=0;i--)
            post[i]=max(post[i+1],height[i]);
        
        long long ans=0;
        for(int i=0;i<n;i++)
            ans+=(min(pre[i],post[i])-height[i]);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends