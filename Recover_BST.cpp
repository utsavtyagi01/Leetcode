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
    vector<int> t;
    TreeNode* curr=NULL;
    int count=0;
    Solution() : curr(nullptr) {} 

    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        t.push_back(root->val);
        inorder(root->right);
    }

    void findSwappedNodes(TreeNode* root, int a, int b) {
        if (!root) return;

        if (count==0&&(root->val == a || root->val==b)){
            curr = root;
            count++;}

        else if ((root->val == b || root->val==a)&& curr!=NULL) {
            int temp = curr->val;
            curr->val = root->val;
            root->val = temp;
            return;
        }

        findSwappedNodes(root->left, a, b);
        findSwappedNodes(root->right, a, b);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int> temp = t;
        int a, b, count = 0;

        sort(temp.begin(), temp.end());

        for (int i = 0; i < t.size(); ++i) {
            if (temp[i] != t[i]) {
                if (count == 0) {
                    a = t[i];
                    ++count;
                } else {
                    b = t[i];
                    break;
                }
            }
        }

        findSwappedNodes(root, a, b);
    }
};
