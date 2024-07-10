class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;

        for(auto &it:logs){
            if(it[0]=='.' && it[1]=='.'&& it[2]=='/'){
                if(!s.empty())
                s.pop();
            }

            else if(it[0]=='.' && it[1]=='/')
            continue;

            else{
                s.push(it);
            }
        }
        int result=0;
        while(!s.empty()){
            s.pop();
            result++;
        }
        return result;
    }
};
