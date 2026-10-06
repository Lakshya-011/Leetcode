/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // bool solve(TreeNode* root,vector<TreeNode*>& a,TreeNode* x){
    //     if(!root) return false;
    //     a.push_back(root);

    //     if(root==x) return true;
    //     if(solve(root->left,a,x) || solve(root->right,a,x)) return true;
    //     a.pop_back();
    //     return false;
    // }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*> a1;
        // vector<TreeNode*> a2;
        // solve(root,a1,p);
        // solve(root,a2,q);
        // int i=0;int j=0;
        // TreeNode* ans=NULL;
        // while(i<a1.size() && j<a2.size()){
        //     if(a1[i]!=a2[j])
        //     break;

        //     ans=a1[i];
        //     i++;
        //     j++;
        // }
        // return ans;
        if(root==NULL || root==p || root==q)
        return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==NULL) return right;
        else if(right==NULL) return left;
        else
        return root;
    }
};