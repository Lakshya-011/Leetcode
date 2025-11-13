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
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        return l;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int size=getlength(head);
        ListNode* temp=head;
        int c=0;
        while(c<size/2){
            temp=temp->next;
            c++;
        }
        return temp;
    }
};