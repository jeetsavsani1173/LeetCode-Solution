//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int isPossible(int a[],int pages,int n){
        int currStudent=1;
        int currPages=0;
        
        for(int i=0;i<n;i++){
            if(currPages+a[i]<=pages){
                currPages+=a[i];
            }else{
                currPages=a[i];
                currStudent++;
            }
        }
        return currStudent;
    }
    int maxOfArray(int a[],int n){
        int ans=0;
        for(int i=0;i<n;i++) ans=max(ans,a[i]);
        return ans;
    }
    int sumOfArray(int a[],int n){
        int ans=0;
        for(int i=0;i<n;i++) ans+=a[i];
        return ans;
    }
    int findPages(int A[], int N, int M) 
    {
        if(N<M) return -1;
        int low=maxOfArray(A,N);
        int high=sumOfArray(A,N);
        int ans=-1;
        while(low<=high){
            int mid=(high-low)/2+low;
            
            if(isPossible(A,mid,N)<=M){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends