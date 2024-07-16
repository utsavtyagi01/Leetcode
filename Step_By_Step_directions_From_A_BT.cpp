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
    TreeNode* LCA(TreeNode* root, int startValue, int destValue){
        if(root==NULL || root->val==startValue || root->val==destValue)
        return root;

        TreeNode *left=LCA(root->left,startValue,destValue);
        TreeNode *right=LCA(root->right,startValue,destValue);

        if(left && right)
        return root;

        if(left)
        return left;

        return right;
    }

    bool func(TreeNode* root, int value, string &s){
        if(root==NULL)
        return 0;
        if(root->val==value)
        return 1;

        s.push_back('L');
        if(func(root->left,value,s))
        return 1;
        s.pop_back();

        s.push_back('R');
        if(func(root->right,value,s))
        return 1;
        s.pop_back();

        return 0;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=LCA(root,startValue,destValue);

        string start,end;
        func(lca,startValue,start);
        func(lca,destValue,end);

        for(int i=0;i<start.size();i++){
            start[i]='U';
        }

        return start+end;

        
    }
};
