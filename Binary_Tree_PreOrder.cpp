class Solution {
public:
    vector<int> ans;
    void preorder(TreeNode* root){
        ans.push_back(root->val);
        if(root->left) preorder(root->left);
        if(root->right) preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;
        preorder(root);
        return ans;
    }
};
