class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> mp;
       for(char ch:words[0]){
                    mp[ch]++;
        }

        for(int i=1;i<words.size();i++){
                unordered_map<char,int> mp2;
                for(char ch:words[i]){
                    mp2[ch]++;
                }
           for (auto it = mp.begin(); it != mp.end(); ) {
                if (mp2.find(it->first) != mp2.end()) {
                    it->second = min(it->second, mp2[it->first]);
                    ++it;
                } else {
                    it = mp.erase(it); 
                }
            }
        }
        vector<string> result;
        for(auto i:mp){
            while(i.second){
            result.push_back(string(1,i.first));
            i.second--;}
        }
        return result;
    }
};
