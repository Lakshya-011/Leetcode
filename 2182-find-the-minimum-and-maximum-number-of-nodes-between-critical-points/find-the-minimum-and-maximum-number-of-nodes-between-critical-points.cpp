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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        vector<int> temp;
        int i=2;
        while(curr->next!=NULL){
            if((curr->val < prev->val && curr->val < curr->next->val)
            || (curr->val > prev->val && curr->val > curr->next->val))
            temp.push_back(i);

            prev=curr;
            curr=curr->next;
            i++;
        }
        if(temp.size()<2)
        return {-1,-1};
        int mi=INT_MAX;
        for(int i=1;i<temp.size();i++){
            int diff= temp[i]-temp[i-1];
            mi=min(mi,diff);
        }
        int mx=temp.back()-temp.front();
        return {mi,mx};
    }
};