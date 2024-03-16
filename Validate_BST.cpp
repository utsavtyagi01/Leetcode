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
    vector<int> result;
    void traversal(TreeNode *root){
        if(root==NULL)
        return;
        traversal(root->left);        
        result.push_back(root->val);
        traversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
        traversal(root);
        vector<int> temp;
        temp=result;
        int count=0;
        for(int i=0;i<result.size()-1;i++){
            if(result[i]==result[i+1])
            count++;
        }
        if(count!=0)
        return false;
        sort(temp.begin(),temp.end());
        if(temp==result)
        return true;
        else 
        return false;
    }
};
