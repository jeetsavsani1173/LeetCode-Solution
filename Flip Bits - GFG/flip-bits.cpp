//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int l=0,r=-1,ans=0,l1=0;
        //kanade sum
        int tsum=0,sum=0;
        for(int i=0;i<n;i++){
            tsum+=(a[i]==0?1:-1);
            if(tsum>0){
                if(sum<tsum){
                    r=i;
                    l=l1;
                    sum=tsum;
                }
            }else{
                tsum=0;
                l1=i+1;
            }
        }
        for(int i=0;i<n;i++){
            if(i<l or i>r){
                ans+=(a[i]==1);
            }else{
                ans+=(a[i]==0);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends