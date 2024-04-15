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
    int sum=0,temp=0;
    void func(TreeNode* root ){
        if(root!=NULL)
        temp=temp*10+root->val;
        if(root->left==NULL && root->right==NULL){
            sum+=temp;
            return;
        }
        if(root->left!=NULL){
        func(root->left);
        temp=temp/10;}
        if(root->right!=NULL){
        func(root->right);
        temp=temp/10;}
    }
    int sumNumbers(TreeNode* root) {
        func(root);
        return sum;
    }
};
