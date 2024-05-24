class Solution {
public:
    int func(vector<string>& words, vector<int> &freq, vector<int> score, int i){
        if(i==words.size())
        return 0;
        bool flag=true;
        int res=0,resn=0;
        for(char ch: words[i]){
            if(freq[ch-'a']==0){
                flag=false;
            }

            freq[ch-'a']--;
            res+=score[ch-'a'];
        }
        
        if(flag){
            res+=func(words,freq,score,i+1);
        }
        else
        res=0;
         for(char ch:words[i]){
            freq[ch-'a']++;
        }
        resn+=func(words,freq,score,i+1);

        return max(res,resn);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        
        for(char ch:letters)
        freq[ch - 'a']++;

        return func(words,freq,score,0);
    }
};
