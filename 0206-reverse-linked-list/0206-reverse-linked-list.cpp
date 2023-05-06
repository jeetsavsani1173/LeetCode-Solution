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
    void helper(ListNode* node){
        if(node==NULL) return;
        if(node->next==NULL){
            newHead=node;
            return;
        }
        helper(node->next);
        node->next->next=node;
        node->next=NULL;
    }
    ListNode* reverseList(ListNode* head) {
        newHead=NULL;
        helper(head);
        return newHead;
    }
};