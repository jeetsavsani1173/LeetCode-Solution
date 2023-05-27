//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    int find_size(Node* root){
        if(root==NULL) return 0;
        return 1+find_size(root->next);
    }
    Node* first;
    void helper(Node* node,int cnt,int size){
        if(node==NULL) return;
        
        helper(node->next,cnt+1,size);
        
        if(cnt>((size-1)/2)){
            int temp=node->data-first->data;
            swap(node->data,first->data);
            first->data=temp;
        }
        first=first->next;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        int sz=find_size(head);
        first=head;
        helper(head,0,sz);
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends