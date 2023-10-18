class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size()&&(s[i]=='I'&&(s[i+1]=='V'||s[i+1]=='X')))
            {
                ans+=m[s[i+1]]-m[s[i]];
                i++;
                continue;
            }
            else if(i+1<s.size()&&(s[i]=='X'&&(s[i+1]=='L'||s[i+1]=='C')))
            {
                ans+=m[s[i+1]]-m[s[i]];
                i++;
                continue;
            }
            else if(i+1<s.size()&&(s[i]=='C'&&(s[i+1]=='D'||s[i+1]=='M')))
            {
                ans+=m[s[i+1]]-m[s[i]];
                i++;
                continue;
            }
           ans+=m[s[i]];
        }
        return ans;
        
    }
};
/*-----------------------------Generalised Approach --------------*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size()&&m[s[i]]<m[s[i+1]])
            {
                ans+=m[s[i+1]]-m[s[i]];
                i++;
                continue;
            }
           ans+=m[s[i]];
        }
        return ans;
        
    }
};
