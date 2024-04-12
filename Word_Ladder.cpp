class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
        return 0;
        unordered_set<string> sett(wordList.begin(),wordList.end());
        queue<pair<string,int> > q;
        q.push({beginWord,1});
        sett.erase(beginWord);
        while(!q.empty()){
            string s=q.front().first;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<s.size();i++){
                char temp=s[i];
                for(char j='a';j<='z';j++){
                    s[i]=j;
                    if(sett.find(s)!=sett.end()){
                        q.push({s,t+1});
                        sett.erase(s);
                    }
                    if(s==endWord){
                        return ++t;
                    }
                }
                s[i]=temp;
            }
        }
        return 0;

    }
};
