//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n+m<=k) return max(arr1[n-1],arr2[m-1]);
        
        int l=-1,r=n-1;
        
        while(l<=r){
            int mid=(r-l)/2+l;
            
            int idx1=mid;
            int idx2=k-idx1-2;
            
            if(idx2>=m){
                l=mid+1;
            }else if(idx2<-1){
                r=mid-1;
            }else{
                int l1=(idx1>=0)?arr1[idx1]:INT_MIN;
                int l2=(idx2>=0)?arr2[idx2]:INT_MIN;
                
                int r1=(idx1+1<n)?arr1[idx1+1]:INT_MAX;
                int r2=(idx2+1<m)?arr2[idx2+1]:INT_MAX;
                
                if(l1<=r2 && l2<=r1) return max(l1,l2);
                else if(l1>r2) r=mid-1;
                else l=mid+1;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends