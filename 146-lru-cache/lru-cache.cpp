class Node{
    public:
    pair<int,int> data;
    Node* prev;
    Node*next;

    Node(int k,int v){
        this->data={k,v};
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
    map<int,Node*> mp;
    Node* head;Node* tail;
    int c;
    LRUCache(int capacity) {
        this->c=capacity;
        mp.clear();
        head=new Node({-1,-1});
        tail=new Node({-1,-1});
        head->next=tail;
        tail->prev=head;
    }
   void deleteNode(Node* node){
        Node* prevNode= node->prev;
        Node* nextNode=node->next;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    void insertAfterHead(Node* node){
        Node* curr=head->next;
        head->next=node;
        node->next=curr;
        node->prev=head;
        curr->prev=node;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())
        return -1;

        Node* node= mp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->data.second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->data.second=value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mp.size()==c){
                Node* node=tail->prev ;
                mp.erase(node->data.first);
                deleteNode(node);
            }
            Node* node=new Node(key,value);
            mp[key]=node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */