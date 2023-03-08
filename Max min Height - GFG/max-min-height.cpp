//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define ll long long

#define vll vector<ll>

class Solution

{

    public:

    bool check(vector<int> &a,int w,int k,long long int mid,int n)

     {

        vector<ll> pref(n+1,0);

        ll val=0;

        for(int i=0;i<n;i++)

 {

            if(i)

 pref[i]+=pref[i-1];

 if(a[i]+pref[i]<mid) 

 {

 ll x=mid-a[i]-pref[i];

 val+=x;

 pref[i]+=x;

 pref[min(i+w,n)]-=x;

 }

 }

        return val<=k;

     }

        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)

        {

            long long int low=0,high=1e14,ans=0;

            while(low<=high)

            {

                long long int mid=(low)+(high-low)/2;

                if(check(a,w,k,mid,n))

                {

                    ans=mid;

                    low=mid+1;

                }

                else

                {

                    high=mid-1;

                }

            }

            return ans;

        }

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends