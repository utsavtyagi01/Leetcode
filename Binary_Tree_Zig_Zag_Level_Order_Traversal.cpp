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
    void func(TreeNode* root, vector<vector<int>> &result){
        if (root == nullptr) return;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int lvl=it.first;
            TreeNode* temp=it.second;
            if (result.size() <= lvl) {
                result.resize(lvl + 1);
            }
            result[lvl].push_back(temp->val);
            if(temp->left!=NULL)
            q.push({lvl+1,temp->left});
            if(temp->right!=NULL)
            q.push({lvl+1,temp->right});
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        func(root,result);
        for(int i=0;i<result.size();i++){
            if(i%2==0)
            continue;
            reverse(result[i].begin(),result[i].end());
        }
        return result;
    }
};
