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
    ListNode* mergesort(vector<ListNode*>& lists, int s, int e){
        if(s==e)
        return lists[s];

        if(s+1==e)
        return merge(lists[s],lists[e]);

        int mid=s+(e-s)/2;
        ListNode* left=mergesort(lists,s,mid);
        ListNode* right=mergesort(lists,mid+1,e);
        return merge(left,right);
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        while(l1&&l2){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        temp->next=l1?l1:l2;
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        return NULL;

        return mergesort(lists,0,lists.size()-1);
    }
};