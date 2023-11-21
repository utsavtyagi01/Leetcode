class Solution {
    bool dfs(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL) return 1;
        if(l!=NULL && r==NULL) return 0;
        if(l==NULL && r!=NULL) return 0;

        bool left = dfs(l->left,r->right);
        bool right = dfs(l->right,r->left);
        bool value = (l->val == r->val);

        return (left && right && value);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};
