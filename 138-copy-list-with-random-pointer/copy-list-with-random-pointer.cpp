/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        Node* curr=head;
        while(curr!=NULL){
            temp->next=new Node(curr->val);
            curr=curr->next;
            temp=temp->next;
        }
        unordered_map<Node*,Node*> mp;
        Node* temp2=head;
        Node* temp3=dummy->next;
        while(temp2!=NULL && temp3!=NULL){
            mp[temp2]=temp3;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        Node* temp4=dummy->next;
        Node* temp5=head;
        while(temp4!=NULL){
            if(temp5->random)
            temp4->random=mp[temp5->random];
            else
            temp4->random=NULL;
            temp4=temp4->next;
            temp5=temp5->next;
        }
        return dummy->next;
    }
};