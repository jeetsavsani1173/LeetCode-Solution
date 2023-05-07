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
    ListNode* temp;
    bool checkPAL(ListNode* node){
        if(node==NULL) return true;
        bool isPAL=(checkPAL(node->next) && (node->val==temp->val));
        temp=temp->next;
        return isPAL;
    }
    bool isPalindrome(ListNode* head) {
        temp=head;
        return checkPAL(head);
    }
};