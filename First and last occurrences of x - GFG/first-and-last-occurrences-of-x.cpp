//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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

vector<int> find(int arr[], int n , int x)
{
    return {find_first_occu(arr,n,x),find_last_occu(arr,n,x)};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends