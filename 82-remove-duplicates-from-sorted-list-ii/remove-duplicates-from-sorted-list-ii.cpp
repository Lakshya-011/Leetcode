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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
        return head;

        ListNode* dummy=new ListNode(-1);
        unordered_map<int,int> mp;
        ListNode* temp=head;
        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        ListNode* curr=dummy;
        ListNode* temp2=head;
        while(temp2!=NULL){
            if(mp[temp2->val]==1){
            curr->next=new ListNode(temp2->val);
            curr=curr->next;
            }
            temp2=temp2->next;
        }
        return dummy->next;
    }
};