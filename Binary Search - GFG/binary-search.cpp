//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int BSearch(int start,int end,int target,int arr[])
    {
        if(start<=end){
            int mid=(end-start)/2+start;
            if(arr[mid]==target) return mid;
            else if(arr[mid]>target) return BSearch(start,mid-1,target,arr);
            else return BSearch(mid+1,end,target,arr);
        }
        return -1;
    }
    int binarysearch(int arr[], int n, int k) {
        return BSearch(0,n-1,k,arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends