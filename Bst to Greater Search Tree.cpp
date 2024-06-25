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
    int sum=0;
    void func(TreeNode *root){
        if(root==NULL)
        return;

        if(root->right!=NULL)
        func(root->right);
        sum=root->val+sum;
        root->val=sum;
        if(root->left!=NULL)
        func(root->left);

    }
    TreeNode* bstToGst(TreeNode* root) {
        func(root);
        return root;
    }
};
