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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head)
        return NULL;
        unordered_set<int> st(nums.begin(),nums.end());
        while(head && st.count(head->val)){
            head=head->next;
        }
        
        if(!head)
        return NULL;
        ListNode* curr=head;
        while(curr && curr->next){
            if(st.count(curr->next->val)){
                curr->next=curr->next->next;
            }
            else{
            curr=curr->next;
            }
        }
        return head;
    }
};