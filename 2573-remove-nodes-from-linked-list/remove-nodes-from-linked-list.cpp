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
 ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* rev = reverseList(head);
        ListNode* prev = rev;
        ListNode* curr = rev->next;
        int mx = rev->val;
         while (curr) {
            if (curr->val < mx) {
                prev->next = curr->next;
                curr = prev->next;
            } else {
                mx = curr->val;
                prev = curr;
                curr = curr->next;
            }
        }
        return reverseList(rev);
    }
};