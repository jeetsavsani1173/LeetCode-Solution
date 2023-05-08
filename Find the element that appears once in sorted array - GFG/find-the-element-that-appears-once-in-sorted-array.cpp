//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int nums[], int n)
    {
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int lval=(mid - 1 >= 0) ? nums[mid-1] : -1;
            int rval=(mid + 1 < n) ? nums[mid+1] : -1;
            
            if(nums[mid]!=lval && nums[mid]!=rval)
                return nums[mid];
            
            if(nums[mid]==lval)
            {
                int lCount=mid-low-1;
                if(lCount&1)
                    high=mid-2;
                else
                    low=mid+1;
            }
            else
            {
                int lCount=mid-low;
                if(lCount&1)
                    high=mid-1;
                else
                    low=mid+2;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends