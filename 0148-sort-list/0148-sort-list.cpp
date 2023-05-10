/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* head;
        ListNode* tail;
        ListNode* dummy=new ListNode(-1);
        head=tail=dummy;

        // merge to sorted LL..
        while(head1!=NULL && head2!=NULL){
            if(head1->val<head2->val){
                tail->next=head1;
                head1=head1->next;
                tail=tail->next;
            }
            else{
                tail->next=head2;
                head2=head2->next;
                tail=tail->next;
            }
        }

        if(head1!=NULL){
            tail->next=head1;
        }
        if(head2!=NULL){
            tail->next=head2;
        }

        return dummy->next;
    }
    ListNode* Find_mid_node(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==NULL) return prev;
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* mid=Find_mid_node(head);
        ListNode* midNext=mid->next;
        mid->next=NULL;
        
        ListNode* left=sortList(head);
        ListNode* right=sortList(midNext);
        
        return mergeTwoLists(left,right);
    }
};