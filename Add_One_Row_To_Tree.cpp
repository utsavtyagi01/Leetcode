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
   void traverse(TreeNode* root, int val, int depth,queue<pair<TreeNode*,int> > q){
    q.push({root,depth});
    while(!q.empty()){
        TreeNode* root1=q.front().first;
        int level=q.front().second;
        q.pop();
        if(level==1){
            TreeNode *node=new TreeNode(val);
            TreeNode *node1=new TreeNode(val);
            node->left=root1->left;
            node1->right=root1->right;
            root1->left=node;
            root1->right=node1;
            continue;
        }
        if(root1->left!=NULL)
        q.push({root1->left,level-1});
        if(root1->right!=NULL)
        q.push({root1->right,level-1});
        
    }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        queue<pair<TreeNode*,int> > q;
        traverse(root,val,depth-1,q);
        return root;
    }
};
