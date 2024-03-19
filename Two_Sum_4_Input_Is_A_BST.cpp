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
    vector<int> traversal;
    void func(TreeNode* root){
        if(root==NULL)
        return;
        traversal.push_back(root->val);
        func(root->left);
        func(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        func(root);
        vector<int> m;
        for(int i=0;i<traversal.size();i++){
            if(find(m.begin(),m.end(),traversal[i])!=m.end())
            return true;
            m.push_back(k-traversal[i]);
        }
        return false;
    }
};
