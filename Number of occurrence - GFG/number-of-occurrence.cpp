//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	
	int find_first_occu(int nums[],int n,int target)
    {
        int l=0,r=n-1,ans=-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]==target)
            {
                ans=mid;
                r=mid-1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
    
    int find_last_occu(int nums[],int n,int target)
    {
        int l=0,r=n-1,ans=-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(nums[mid]==target)
            {
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
    
	int count(int arr[], int n, int x) {
	    int first=find_first_occu(arr,n,x);
	    int last=find_last_occu(arr,n,x);
	    if(first==-1 || last==-1) return 0;
	    return last-first+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends