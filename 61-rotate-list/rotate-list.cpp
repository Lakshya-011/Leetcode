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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp=head;
        int l=0;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        ListNode* ptr1=head;
        ListNode* ptr2=head;
        k=k%l;
        if(k==0){
            return head;
        }
        while(k>0){
            ptr2=ptr2->next;
            k--;
        }
        while(ptr2->next!=NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr2->next=head;
        head=ptr1->next;
        ptr1->next=NULL;
        return head;
    }
};