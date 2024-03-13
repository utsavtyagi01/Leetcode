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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode *node = new TreeNode(val);
            root=node;
            return root;
        }
        else if(val>root->val&&root->right==NULL){
            TreeNode *node= new TreeNode(val);
            //node->val=val;
            //node->left=NULL;
            //node->right=NULL;
            root->right=node;
        }
        else if(val<root->val&&root->left==NULL){
            TreeNode *node1=new TreeNode(val);
            //node1->val=val;
            //node1->left=NULL;
            //node1->right=NULL;
            root->left=node1;
        }
        else if(val<root->val){
           root->left=(insertIntoBST(root->left,val));
        }
        else if(val>root->val){
            root->right=(insertIntoBST(root->right,val));
        }
        return root;

    }
};
