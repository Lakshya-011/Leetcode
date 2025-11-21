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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
        return head;
        int l=0;
        ListNode* temp=head;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        } 
        int p=l-n+1;
        if(p==1){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        int i=1;
        while(i<p){
            prev=curr;
            curr=curr->next;
            i++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
    }
};