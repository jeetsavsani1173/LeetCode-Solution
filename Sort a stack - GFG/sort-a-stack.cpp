//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int> &st,int val,int prev)
{
    if(st.size()==0){
        if(val<=prev)
            st.push(val);
        return;
    }
    int currVal=st.top();
    st.pop();
    insert(st,val,currVal);
    st.push(currVal);
    if(val<=prev && val>currVal)
        st.push(val);
}
void sortStack(stack<int> &stack){
    if(stack.size()==0) return;
    int val=stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack,val,1e9+5);
}
void SortedStack :: sort()
{
    sortStack(s);
}