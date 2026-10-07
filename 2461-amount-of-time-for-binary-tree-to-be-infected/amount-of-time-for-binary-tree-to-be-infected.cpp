/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, int start){
        if(!root) return NULL;
        if(root->val==start)
        return root;
        
        TreeNode * left=solve(root->left,start);
        if(left) return left;
        return solve(root->right,start);
    }
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                mp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mp;
        parent(root,mp);
        int t=0;
        queue<TreeNode*> q;
        TreeNode* v=solve(root,start);
        q.push(v);
        unordered_map<TreeNode*,bool> vis;
        vis[v]=true;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left && !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left]=true;
            }
            if(curr->right && !vis[curr->right]){
                q.push(curr->right);
                vis[curr->right]=true;
            }
            if(mp[curr] && !vis[mp[curr]]){
                q.push(mp[curr]);
                vis[mp[curr]]=true;
                }
            }
            t++;
        }
        return t-1;
    }
};