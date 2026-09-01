class node{
    public:
    int data;
    int i;
    int j;
    node(int data,int r,int c){
        this->data=data;
        i=r;
        j=c;
    }
};
class comp{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*, vector<node*> , comp> pq;
        int n=nums.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            node* temp=new node(nums[i][0],i,0);
            mx=max(mx,temp->data);
            pq.push(temp);
        }
        int diff=INT_MAX;
        vector<int> ans={-1,-1};
        while(pq.size()>0){
            node* temp=pq.top();
            int mi=temp->data;
            if(mx-mi < diff){
                diff=mx-mi;
                ans={mi,mx};
            }
            pq.pop();

            int i=temp->i;
            int j=temp->j;

            if(j+1<nums[i].size()){
                node* next=new node(nums[i][j+1],i,j+1);
                mx=max(mx,next->data);
                pq.push(next);
            }
            else{
                break;
            }
        }
        return ans;
    }
};