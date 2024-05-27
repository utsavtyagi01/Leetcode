class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1||s.size()==0)
        return s.size();
        unordered_set<char> mp;
        int i=0,j=0,result=0;
        for(int j=0;j<s.size();j++){
            if(mp.find(s[j])==mp.end()){
                mp.insert(s[j]);
                result=max(result,j-i+1);
            }
            else{
                while(mp.find(s[j])!=mp.end()){
                    mp.erase(s[i]);
                    i++;
                }
                mp.insert(s[j]);
            }
        }
        return result;
    }
};
