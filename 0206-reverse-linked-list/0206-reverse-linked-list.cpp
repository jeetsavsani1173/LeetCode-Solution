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
    ListNode* newHead;
    void helper(ListNode* curr,ListNode* prev){
        if(curr==NULL) return;
        if(curr->next==NULL){
            newHead=curr;
        }
        helper(curr->next,curr);
        curr->next=prev;
    }
    ListNode* reverseList(ListNode* head) {
        helper(head,NULL);
        return newHead;
    }
};