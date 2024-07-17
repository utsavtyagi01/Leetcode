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
    vector<TreeNode*> result;
    TreeNode* func(TreeNode* root, unordered_set<int> &mp){
        if(root==NULL)
        return NULL;
        root->left=func(root->left,mp);
        root->right=func(root->right,mp);

        if(mp.find(root->val)!=mp.end()){
            if(root->left!=NULL)
            result.push_back(root->left);
            if(root->right!=NULL)
            result.push_back(root->right);

            return NULL;
        }

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> mp(to_delete.begin(),to_delete.end());
        TreeNode* temp=func(root,mp);
        if(temp)
        result.push_back(root);

        return result;
    }
};
