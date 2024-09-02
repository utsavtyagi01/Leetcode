/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void createtree(unordered_map<TreeNode*,TreeNode*> &mp, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            if(it->left){
                mp[it->left]=it;
                q.push(it->left);
            }
            if(it->right){
                mp[it->right]=it;
                q.push(it->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;

        createtree(mp,root);

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> stt;
        stt.insert(target);
        while(!q.empty() && k){
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left && stt.find(curr->left)==stt.end()){
                    q.push(curr->left);
                    stt.insert(curr->left);
                }

                if(curr->right && stt.find(curr->right)==stt.end()){
                     q.push(curr->right);
                     stt.insert(curr->right);
                }
               

                if(mp.find(curr)!=mp.end() && stt.find(mp[curr])==stt.end()){
                     q.push(mp[curr]);
                     stt.insert(mp[curr]);
                }
               
            }
            k--;
        }

        vector<int> result;

        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
