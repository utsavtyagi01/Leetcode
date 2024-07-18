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
    int result=0;
    vector<int> func(TreeNode* root, int dist){
        if(root==NULL)
        return {};
        if(root->left==NULL && root->right==NULL)
        return {1};
        vector<int> l=func(root->left,dist);
        vector<int> r=func(root->right,dist);
 
        int i=0,j=0;
        while(i<l.size()){
            while(j<r.size()){
                if(l[i]+r[j]<=dist)
                result++;
                j++; 
                }
            j=0;
            i++; 
        }
        i=0,j=0;
        vector<int> set;
        while(i<l.size()){
        if(l[i]+1<dist)
        set.push_back(l[i]+1);
        i++;}

        while(j<r.size()){
        if(r[j]+1<dist)
        set.push_back(r[j]+1);
        j++;}

        return set;

    }
    int countPairs(TreeNode* root, int distance) {
        result=0;
        func(root,distance);
        return result;
    }
};
