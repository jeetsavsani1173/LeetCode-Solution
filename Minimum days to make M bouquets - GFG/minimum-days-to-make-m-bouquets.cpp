//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int check(vector<int>& bloomDay,int days,int k){
        int totalBouquets=0;
        int count=0;
        
        for(auto it:bloomDay){
            if(it<=days){
                count++;
            }else{
                count=0;
            }
            if(count==k){
                totalBouquets++;
                count=0;
            }
        }
        return totalBouquets;
    }
    int solve(int m, int k, vector<int> &bloomDay){
      int n=bloomDay.size();
        if(1ll*m*k>1ll*n) return -1;
        
        int l=1,r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=r){
            int mid=(r-l)/2+l;
            
            if(check(bloomDay,mid,k)>=m){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends