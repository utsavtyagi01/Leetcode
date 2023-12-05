class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> value(nums2.size(), -1);

        // Find the next greater element indices in nums2
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && (nums2[i] > nums2[st.top()])) {
                value[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans;
        // Use the indices from value directly to access the next greater elements
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    ans.push_back(value[j] != -1 ? nums2[value[j]] : -1);
                }
            }
        }

        return ans;
    }
};
