//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long temp[],long long int l,long long int mid,long long int r)
    {
        long long ans=0ll;
        long long i=l,j=mid+1,k=l;
        
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }else{
                temp[k++]=arr[j++];
                ans+=(mid-i+1);
            }
        }
        
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        
        while(j<=r){
            temp[k++]=arr[j++];
        }
        
        for(i=l;i<=r;i++){
            arr[i]=temp[i];
        }
        
        return ans;
    }
    long long int mergeSort(long long arr[],long long temp[],long long int l,long long int r)
    {
        long long rres=0;
        if(l<r){
            long long int mid=(r-l)/2+l;
            rres+=mergeSort(arr,temp,l,mid);
            rres+=mergeSort(arr,temp,mid+1,r);
            
            rres+=merge(arr,temp,l,mid,r);
        }
        return rres;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return mergeSort(arr,temp,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends