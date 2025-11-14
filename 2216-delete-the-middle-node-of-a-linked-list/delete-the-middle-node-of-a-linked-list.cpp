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
    int getlength(ListNode* head){
        int l=0;
        ListNode* temp=head;
        while(temp){
            l++;
            temp=temp->next;
        }
        return l;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next== NULL)
        return NULL;
        // ListNode* curr=head;
        // ListNode* prev=NULL;
        // int l=getlength(head);
        // int c=0;
        // while(c<l/2){
        //     prev=curr;
        //     curr=curr->next;
        //     c++;
        // }
        // prev->next=curr->next;
        // curr->next=NULL;
        // delete curr;

        ListNode* fast=head;
        ListNode*  slow=head;
        ListNode* prev=NULL;

        while(fast!= NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        delete slow;
        return head;
    }
};