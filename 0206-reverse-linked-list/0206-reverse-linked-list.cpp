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
    ListNode* newHead=NULL;
    void helper(ListNode* head)
    {
        if(head==NULL) return;
        if(head->next==NULL){
            newHead=head;
            return;
        }
        helper(head->next);
        head->next->next=head;
        head->next=NULL;
    }
    ListNode* reverseList(ListNode* head) {
        helper(head);
        return newHead;
    }
};