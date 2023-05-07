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
        ListNode* tail;
        ListNode* dummy=new ListNode(-1);
        tail=dummy;
        
        while(head1 && head2){
            if(head1->val>head2->val){
                // take element from second Linkedlist
                tail->next=head2;
                tail=tail->next;
                head2=head2->next;
            }else{
                // take from first LL.
                tail->next=head1;
                tail=tail->next;
                head1=head1->next;
            }
        }
        
        if(head1){
            tail->next=head1;
        }
        
        if(head2){
            tail->next=head2;
        }
        
        return dummy->next;
    }
};