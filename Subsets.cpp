vector<vector<int>> ans;
vector<vector<int>> ans1;
vector<int> temp;
void func(vector<int> &nums,int i){
    if(i==nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    func(nums,i+1);
    temp.pop_back();
    func(nums,i+1);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        func(nums,0);
        ans1=ans;
        ans.clear();
        return ans1;
        
    }
};
