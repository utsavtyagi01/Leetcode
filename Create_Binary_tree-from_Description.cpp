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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        set<int> child;
        TreeNode * root;
        for(auto it: descriptions){
            if(mp.find(it[0])==mp.end()){
                TreeNode *node=new TreeNode(it[0]);
                mp[it[0]]=node;
            }
            if(mp.find(it[1])==mp.end()){
                TreeNode *node=new TreeNode(it[1]);
                mp[it[1]]=node;
            }
            if(it[2]==1){
                mp[it[0]]->left=mp[it[1]];
            }
            else if(it[2]==0){
                mp[it[0]]->right=mp[it[1]];
            }
            child.insert(it[1]);
        }
      for(auto it :descriptions){
            if(child.count(it[0])==0)
            root=mp[it[0]];}
    return root;
    }

};
