vector<int> temp;
vector<vector<int>> ans;
vector<vector<int>> ans1;

void func(vector<int> &arr, int i, int target, int currentSum) {
    if (currentSum == target) {
        ans.push_back(temp);
        return;
    }
    if (i == arr.size() || currentSum > target) {
        return;
    }

    temp.push_back(arr[i]);
    func(arr, i + 1, target, currentSum + arr[i]);
    temp.pop_back();

    while (i < arr.size() - 1 && arr[i] == arr[i + 1]) {
        i++;
    }

    func(arr, i + 1, target, currentSum);
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        func(candidates, 0, target, 0);
        ans1=ans;
        ans.clear();
        return ans1;
    }
};
