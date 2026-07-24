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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* slow=head->next;
        ListNode* fast=head;
        ListNode* temp=slow;
        while(slow && slow->next){
            fast->next=slow->next;
            fast=fast->next;

            slow->next=fast->next;
            slow=slow->next;
        }
        fast->next=temp;
        return head;
    }   
};