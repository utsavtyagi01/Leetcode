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
    vector<int> node;
    void inorder(TreeNode * root){
        if(root==NULL)
        return;
        inorder(root->left);
        node.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* create( int start,int end){
        if(start>end)
        return NULL;
        int mid=start+(end-start)/2;
        TreeNode *root=new TreeNode(node[mid]);
        root->left=create(start,mid-1);
        root->right=create(mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);

        return create(0,node.size()-1);

    }
};
