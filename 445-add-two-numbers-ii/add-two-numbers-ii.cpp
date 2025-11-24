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
    while(curr){
        ListNode* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=rev(l1);
        ListNode* head2=rev(l2);

        int c=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(head1!=NULL || head2!=NULL || c){
            int v1=(head1 ? head1->val:0);
            int v2= (head2 ? head2->val:0);
            int s=v1+v2+c;
                c=s/10;
                temp->next=new ListNode(s%10);
                  temp=temp->next;
            if(head1)head1=head1->next;
            if(head2)head2=head2->next;
        }
        return rev(dummy->next);
    }
};