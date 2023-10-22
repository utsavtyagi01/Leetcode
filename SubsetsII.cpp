vector<vector<int>> ans;
vector<int> temp;
vector<vector<int>> ans1;
void func(vector<int> &arr,int i){
    if(i==arr.size()){
        if(find(ans.begin(),ans.end(),temp)!=ans.end())
        return;
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[i]);
    func(arr,i+1);
    temp.pop_back();


    func(arr,i+1);
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        func(nums,0);
        ans1=ans;
        ans.clear();
        return ans1;
    }
};
