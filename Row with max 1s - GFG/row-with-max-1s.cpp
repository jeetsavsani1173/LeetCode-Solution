//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int find(int start,int end,vector<int> &arr){
        int idx=end+1;
        while(start<=end){
            int mid=(end-start)/2+start;
            
            if(arr[mid]==1){
                idx=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return idx;
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int count=0;
	    int ans=-1;
	    for(int i=0;i<n;i++){
	        int idx=find(0,m-1,arr[i]);
	        int element=m-idx;
	        if(element>count){
	            count=element;
	            ans=i;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends