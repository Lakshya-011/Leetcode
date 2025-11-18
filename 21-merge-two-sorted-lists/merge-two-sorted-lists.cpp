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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode* temp=new ListNode(-1);
        // ListNode* tail=temp;
        // while(list1!=NULL && list2!=NULL){
        //     if(list1->val<list2->val){
        //         tail->next=list1;
        //         list1=list1->next;
        //     }
        //     else{
        //         tail->next=list2;
        //         list2=list2->next;
        //     }
        //     tail=tail->next;
        // }
        // if(!list1)
        // tail->next=list1;
        // else
        // tail->next=list2;

        // return temp->next;
        ListNode* temp;
        if(list1==NULL && list2== NULL)
        return NULL;
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val<list2->val){
            temp=list1;
            list1=list1->next;
        }
        else{
            temp=list2;
            list2=list2->next;
        }
        ListNode* dummy=temp;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
            temp->next=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;
        }
        temp=temp->next;
        }

        if(!list1==NULL){
        temp->next=list1;
        }
        
        if(!list2==NULL){
        temp->next=list2;
        }
        return dummy;
    }
};