class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;

        for(auto& i:nums2){
            mp[i]++;
        }
        vector<int> result;
        for(auto& i:nums1){
            if(mp.find(i)!=mp.end()){
              result.push_back(i);
              mp[i]--;
               if (mp[i] == 0) {
                    mp.erase(i);
                }
              
              }
        }

        return result;
    }
};
