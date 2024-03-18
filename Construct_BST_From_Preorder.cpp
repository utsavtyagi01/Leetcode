TreeNode* func(vector<int>& inorder, int is, int ie, vector<int>& preorder, int& ps, map<int,int>& m) {
        if (is > ie || ps == preorder.size()) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[ps]);
        int mid = m[preorder[ps]];
        ps++;
        node->left = func(inorder, is, mid - 1, preorder, ps, m);
        node->right = func(inorder, mid + 1, ie, preorder, ps, m);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        int ps = 0; 
        return func(inorder, 0, inorder.size() - 1, preorder, ps, m);
    }
