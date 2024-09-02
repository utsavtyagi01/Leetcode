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
     TreeNode* func(vector<int>& postorder, vector<int>& inorder, int in1, int in2, int &p){
        if(p==postorder.size())
        return NULL;
        
        if(in2<in1)
        return NULL;

        TreeNode* node=new TreeNode(postorder[p]);
        int i=in1;
        
        while(i<=in2 && inorder[i]!=postorder[p])
        i++;

        p--;
        
        node->right=func(postorder,inorder,i+1,in2,p);
        node->left=func(postorder,inorder,in1,i-1,p);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int temp=postorder.size()-1;
        return func(postorder,inorder,0,inorder.size()-1,temp);
    }
};
