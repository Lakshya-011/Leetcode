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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* d1=new ListNode(0,NULL);
        ListNode* d2=new ListNode(0,NULL);
        ListNode* s=d1;
        ListNode* e=d2;
        while(temp!=NULL){
            if(temp->val < x){
                s->next=temp;
                s=s->next;
            }
            else{
                e->next=temp;
                e=e->next;
            }
            temp=temp->next;
        }
        s->next=d2->next;
        e->next=NULL;
        ListNode* ans=d1->next;
        delete d1;
        delete d2;
        return ans;
    }
};