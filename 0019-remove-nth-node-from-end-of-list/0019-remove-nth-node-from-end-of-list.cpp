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
    int find_size(ListNode* head){
        if(head==NULL) return 0;
        return 1+find_size(head->next);
    }
    void dfs(ListNode* head,int count,int target)
    {
        if(head==NULL) return;
        dfs(head->next,count+1,target);
        if(count==target){
            head->next=head->next->next;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=find_size(head);
        if(sz==n) return head->next;
        dfs(head,1,sz-n);
        return head;
    }
};