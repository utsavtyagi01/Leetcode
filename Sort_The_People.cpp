class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string,greater<int>> mp;

        for(int i=0;i<names.size();i++){
            mp.insert({heights[i],names[i]});
        }

        vector<string> result;
        
        for(auto it:mp)
        result.push_back(it.second);

        return result;
    }
};
