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
    ListNode* merge_list(vector<ListNode*>& lists,int l,int r)
    {
        if(l>r)
            return NULL;
        if(l==r)
            return lists[l];
        
        int mid=(l+r)/2;
        ListNode* first=merge_list(lists,l,mid);
        ListNode* second=merge_list(lists,mid+1,r);
        
        return mergeTwoLists(first,second);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        
        return merge_list(lists,0,lists.size()-1);
    }
};