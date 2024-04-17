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
    string temp="",result="";
    int flag=1;
    void func(TreeNode* root){
        if(root!=NULL)
        temp+=char(root->val+'a');
        if(root!=NULL&&(root->left==NULL && root->right==NULL)){
            string temp1=temp;
            reverse(temp1.begin(),temp1.end());
            if(flag==1){
            result=temp1;
            flag=0;}
            else{
                if(result>temp1)
                result=temp1;
            }
        }
        if(root->left!=NULL){
        func(root->left);
        temp.pop_back();}
        if(root->right!=NULL){
        func(root->right);
        temp.pop_back();}
    }
    string smallestFromLeaf(TreeNode* root) {
        func(root);
        return result;
    }
};
