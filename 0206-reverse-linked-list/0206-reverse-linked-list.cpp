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
    ListNode* first;
    int count=0;
    int find_size(ListNode* node)
    {
        if(node==NULL) return 0;
        return 1+find_size(node->next);
    }
    void helper(ListNode* last,int &sz)
    {
        if(last==NULL) return;
        helper(last->next,sz);
        
        if(count<(sz/2)){
            swap(first->val,last->val);
        }
        count++;
        first=first->next;
    }
    ListNode* reverseList(ListNode* head) {
        int sz=find_size(head);
        first=head;
        count=0;
        helper(head,sz);
        return head;
    }
};