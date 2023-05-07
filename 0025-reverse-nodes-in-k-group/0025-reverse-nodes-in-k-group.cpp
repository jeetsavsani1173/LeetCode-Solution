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
    int find_len(ListNode* head){
        if(head==NULL) return 0;
        return 1+find_len(head->next);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode *curr=dummy,*next=dummy,*prev=dummy;
        int len=find_len(head);
        
        while(len>=k){
            curr=prev->next;
            next=curr->next;
            for(int i=1;i<k;i++){
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            prev = curr;
            len-=k;
        }
        return dummy->next;
    }
};