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
    int result=0;
    int func(TreeNode* root){
        if(root==NULL)
        return 0;
        int l=func(root->left);

        int r=func(root->right);
        if(result<(l+r))
        result=l+r;
        return max(l,r)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int x=func(root);
        return result;
    }
};
