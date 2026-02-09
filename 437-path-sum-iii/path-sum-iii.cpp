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
    int count(TreeNode* root, long long targetSum){
        if(root==NULL)
        return 0;
        int c=0;
        if(targetSum==root->val){
            c++;
        }
        c+=count(root->left, targetSum-root->val);
        c+=count(root->right, targetSum-root->val);

        return c;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        return 0;

        return count(root,targetSum)+pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};