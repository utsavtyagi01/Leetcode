class Solution {

public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        int i=0;
        while(i<s.size()){
            m[s[i]]++;
            i++;
        }
        string ans="";
        vector<pair<char, int>> freqVector(m.begin(), m.end());
        sort(freqVector.begin(), freqVector.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        });

        //sort(m.begin(),m.end(),cmp);
        for (const pair<char, int>& p : freqVector) {
    ans += string(p.second, p.first);
}

        return ans;
    }
};
