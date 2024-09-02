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
    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int in1, int in2, int &p){
        if(p==preorder.size())
        return NULL;
        
        if(in2<in1)
        return NULL;

        TreeNode* node=new TreeNode(preorder[p]);
        int i=in1;
        
        while(i<=in2 && inorder[i]!=preorder[p])
        i++;

        p++;
        node->left=func(preorder,inorder,in1,i-1,p);
        node->right=func(preorder,inorder,i+1,in2,p);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int temp=0;
        return func(preorder,inorder,0,inorder.size()-1,temp);
    }
};
