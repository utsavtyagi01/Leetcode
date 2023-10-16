
void func(vector<string> &v,string &s,int open,int close){
    if(open==0&&close==0){
        v.push_back(s);
        return;
    }
    if(open>0){
        s.push_back('(');
        func(v,s,open-1,close);
        s.pop_back();
    }
     if(close>open){
        s.push_back(')');
        func(v,s,open,close-1);
        s.pop_back();
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s="";
        func(v,s,n,n); 
        return v;
    }
};
