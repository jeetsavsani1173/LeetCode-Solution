//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n=nums1.size(),m=nums2.size();
        if(n<m) return MedianOfArrays(nums2,nums1);
        int l=-1,r=(n+m-1)/2;
        int k=r+1;
        while(l<=r){
            int mid=(r-l)/2+l;
            
            int idx1=mid;
            int idx2=k-idx1-2;
            
            if(idx2>=m){
                l=mid+1;
            }else if(idx2<-1){
                r=mid-1;
            }else{
                int l1=(idx1>=0)?nums1[idx1]:INT_MIN;
                int l2=(idx2>=0)?nums2[idx2]:INT_MIN;
                
                int r1=(idx1+1<n)?nums1[idx1+1]:INT_MAX;
                int r2=(idx2+1<m)?nums2[idx2+1]:INT_MAX;
                
                if(l1<=r2 && l2<=r1){
                    if((m+n)%2==0){
                        return 1.00000*(max(l1,l2)+min(r1,r2))/2.00000;
                    }else{
                        return 1.00000*max(l1,l2);
                    }
                }
                else if(l1>r2) r=mid-1;
                else l=mid+1;
            }
        }
        return 0.00;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends