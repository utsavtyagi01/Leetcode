class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp1,mp2;

        for(int i:target)
        mp1[i]++;

        for(int j:arr)
        mp2[j]++;

        for(auto it:mp1){
            if(mp2[it.first]!=it.second)
            return false;
        }

        return true;
    }
};
