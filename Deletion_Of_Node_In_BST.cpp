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
    TreeNode* func(TreeNode *root, int key){
        if(root->left==NULL)
        return root->right;
        else if(root->right==NULL)
        return root->left;
        TreeNode* max=root->left;
        while(max->right!=NULL)
        max=max->right;
        max->right=root->right;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        return root;
        if(root->val==key){
            root=func(root,key);
        }
        TreeNode* temp=root;
        while(root!=NULL){
            if(root->left!=NULL && root->left->val==key){
                root->left=func(root->left,key);
                break;
            }
            else if(root->right!= NULL && root->right->val==key){
                root->right=func(root->right,key);
                break;
            }
            else if(root->val>key)
            root=root->left;

            else if(root->val<key)
            root=root->right;
        }
        return temp;

    }
};
