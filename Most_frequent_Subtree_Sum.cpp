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
    int maxx=0;
    int dfs(TreeNode* root,unordered_map<int,int> &sum){
        if(root==NULL)
        return 0;

        int ls=dfs(root->left,sum);
        int rs=dfs(root->right,sum);

        sum[ls+rs+root->val]++;
        maxx=max(maxx,sum[ls+rs+root->val]);
        return ls+rs+root->val;

    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
       vector<int> ans;
        if(!root)
        return ans;
      unordered_map<int,int> sum;
       dfs(root,sum); 
       for(auto i:sum){
        if(i.second==maxx)
        ans.push_back(i.first);
       }
       return ans;
    }
};
