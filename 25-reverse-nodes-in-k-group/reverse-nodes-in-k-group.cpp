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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        return head;

        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        int l=0;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        if(l<k)
        return head;
        int c=0;
        while(curr!=NULL && c<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;
        }
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
};