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
    private:
    ListNode* rev(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;

        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL)
        return head;
        ListNode* head1=rev(head);
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int c=0;
        while(head1!=NULL || c){
            int s= head1? head1->val:0;
            int v= (2 *s) +c;
            c=v/10;
            temp->next=new ListNode(v%10);
            temp=temp->next;
            if(head1)
            head1=head1->next;
        }
        return rev(dummy->next);
    }
};