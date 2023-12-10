class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s;
        for(auto i:nums)
        s.insert(i);
        int maxi = nums.size();
        vector<int> ans;
        for(int i=1;i<=maxi;i++){
            if(s.find(i)==s.end())
            ans.push_back(i);
        }
        return ans;
    }
};
