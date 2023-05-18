//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int size;
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int> > mn;
    Solution() {
        size=0;
    }
    //Function to insert heap.
    void insertHeap(int &num)
    {
        if(mn.size()==0 || mx.size()==0){
            mx.push(num);
        }else{
            int top1=mx.top();
            if(num<=top1){
                mx.push(num);
            }else{
                mn.push(num);
            }
        }
        balanceHeaps();
        size++;
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int mx_size=mx.size();
        int mn_size=mn.size();
        while(abs(mn_size-mx_size)>1){
            if(mn.size()>mx.size()){
                mx.push(mn.top());
                mn.pop();
                mx_size++,mn_size--;
            }else{
                mn.push(mx.top());
                mx.pop();
                mn_size++,mx_size--;
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(size==1){
            if(mx.size()>mn.size())
                return (double)mx.top()*1.0;
            else
                return (double)mn.top()*1.0;
        }
        
        if(size%2==0){
            double ans=mx.top()+mn.top();
            return ans/2.0;
        }else{
            if(mx.size()<mn.size()){
                return mn.top()*1.0;
            }else{
                return mx.top()*1.0;
            }
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends