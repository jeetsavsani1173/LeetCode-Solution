//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseList(Node* head) {
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        l1=reverseList(l1);
        l2=reverseList(l2);
        Node* dummy=new Node(-1);
        Node* curr=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int d1=(l1==NULL)?(0):(l1->data);
            int d2=(l2==NULL)?(0):(l2->data);
            
            Node* temp=new Node((d1+d2+carry)%10);
            carry=(d1+d2+carry)/10;
            
            curr->next=temp;
            curr=curr->next;
            
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        
        if(carry>0){
            Node* temp=new Node(carry);
            curr->next=temp;
            curr=curr->next;
        }
        dummy->next=reverseList(dummy->next);
        return dummy->next;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends