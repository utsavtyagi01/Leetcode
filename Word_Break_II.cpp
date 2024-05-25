class Solution {
public:
    vector<string> result;
    unordered_set<string> set;
    void func(string s,int i,string &temp){
        if(i==s.size())
        {
            result.push_back(temp);
            return;
        }
        string word;
        for(int j=i;j<s.size();j++){
            word+=s[j];
            if(set.count(word)){
                string temp2=temp;
                temp+=word;
                if(!(j==s.size()-1))
                temp+=" ";
                func(s,j+1,temp);
                temp=temp2;

            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string temp;
        for(auto ch:wordDict)
        set.insert(ch);
        func(s,0,temp);
        return result;
    }
};
