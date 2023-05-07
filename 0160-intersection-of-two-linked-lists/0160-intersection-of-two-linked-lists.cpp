/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        
        if(fast==NULL || fast->next==NULL) return NULL;
        
        ListNode* curr1=head;
        ListNode* curr2=slow;
        while(curr1!=curr2){
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return curr1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tailB=headB;
        while(tailB->next!=NULL)
            tailB=tailB->next;
        
        tailB->next=headB;
        ListNode* ans=detectCycle(headA);
        tailB->next=NULL;
        return ans;
    }
};