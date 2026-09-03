class node{
    public:
    int data;
    int i;
    int j;
    node(int d,int r,int c){
        this->data=d;
        this->i=r;
        this->j=c;
    }
};
class comp{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<node*,vector<node*>,comp> pq;
        for(int i=0;i<min((int)nums1.size(),k);i++){
            pq.push(new node(nums1[i]+nums2[0],i,0));
        }

        while(k>0 && !pq.empty()){
            node* temp=pq.top();
            pq.pop();
            ans.push_back({nums1[temp->i],nums2[temp->j]});
            k--;
            int i=temp->i;
            int j=temp->j;
            if(j+1<nums2.size()){
                pq.push(new node(nums1[i]+nums2[j+1],i,j+1));
            }
        }
        return ans;
    }
};