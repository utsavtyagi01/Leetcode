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
public:
    TreeNode *result;
    void func(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)
        return;
        if(root->val>p->val && root->val>q->val)
        lowestCommonAncestor(root->left,p,q);
        else if(root->val<p->val && root->val<q->val)
        lowestCommonAncestor(root->right,p,q);
        else
        result=root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        func(root,p,q);
        return result;

    }
};
