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
    private:
    int maxi=0;
    int solve(TreeNode* root){
        if(root==NULL)
        return 0;

        if(root->left==NULL && root->right==NULL)
        return 1;

        int x=solve(root->left);
        int y=solve(root->right);
        maxi=max(maxi,x+y);
        return 1+max(x,y);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return maxi;
    }
};