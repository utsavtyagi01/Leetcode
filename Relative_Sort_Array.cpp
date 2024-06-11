class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        vector<int> result,remain;
        for(auto &i:arr2)
        mp[i]=0;

        for(int i:arr1){
            if(mp.find(i)==mp.end())
            remain.push_back(i);
            else
            mp[i]++;
        }
        sort(remain.begin(),remain.end());

        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]){
                result.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        result.insert(result.end(),remain.begin(),remain.end());
        return result;
    }
};
