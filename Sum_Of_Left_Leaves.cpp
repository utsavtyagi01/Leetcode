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
    int sum=0;
    int flag=0;
    void func(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
            sum+=root->left->val;
        }
        func(root->left);
        func(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
        return 0;

        func(root);
        return sum;
    }
};
