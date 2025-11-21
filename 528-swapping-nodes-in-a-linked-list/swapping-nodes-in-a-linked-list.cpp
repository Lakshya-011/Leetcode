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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next)
        return head;
        ListNode* a=head;
        // ListNode* b=NULL;
        ListNode* c=head;
        // ListNode* d=NULL;

        int l=0;
        ListNode* temp=head;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        int pos=l-k+1;
        int i=0;
        while(i<k-1){
            // b=a;
            a=a->next;
            i++;
        }
        int j=0;
        while(j<pos-1){
            // d=c;
            c=c->next;
            j++;
        }
        // b->next=d->next;
        swap(a->val,c->val);
        return head;

    }
};