class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stack<char> stack;
        int i=s.size()-1,j=0;
        while(j>=0&&s[j]==' ')
        {
            j++;
        }
        while(i>=0&&s[i]==' ')
        {
            i--;
        }
        while(i>=j){
            if(s[i]==' '&&!stack.empty()){
                while(!stack.empty()){
                ans+=stack.top();
                stack.pop();
                }
                if(i!=j||s[i-1]!=' ')
                ans+=' ';
                i--;
                continue;
             }
             else if(s[i]!=' '){
                 stack.push(s[i]);
                 i--;
             }
             else
             i--;
             
       }
       while(!stack.empty()){
                ans+=stack.top();
                stack.pop();
                }
       return ans;
    }
};
