// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int count=0;
        int temp=b;
        while(temp){
            count+=((temp&1));
            temp/=2;
        }
        
        vector<int> pos;
        for(int i=0;i<31;i++)
        {
            if((1<<i)&a) pos.push_back(i);
        }
        
        if(count>pos.size()){
            count-=pos.size();
            for(int i=0;i<31 && count;i++)
            {
                if((1<<i)&a) continue;
                else{
                    a=(a|(1 << (i)));
                    count--;
                }
            }
            return a;
        }else{
            int ans=0;
            reverse(pos.begin(),pos.end());
            for(int i=0;i<pos.size() && count;i++)
            {
                ans=(ans|(1 << (pos[i])));
                count--;
            }
            return ans;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends