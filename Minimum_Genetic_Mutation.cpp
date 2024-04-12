class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(find(bank.begin(),bank.end(),endGene)==bank.end())
        return -1;
        unordered_set<string> sett(bank.begin(),bank.end());
        queue<pair<string,int> >  q;
        q.push({startGene,0});
        sett.erase(startGene);
        while(!q.empty()){
            string s=q.front().first;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<s.size();i++){
                char temp=s[i];
                for(char c = 'A';c<='Z';c++){
                    s[i]=c;
                    if(sett.find(s)!=sett.end()){
                        q.push({s,t+1});
                        sett.erase(s);
                    }
                    if(s==endGene)
                    return ++t;
                }
                s[i]=temp;
            }
        }
        return -1;

    }
};
