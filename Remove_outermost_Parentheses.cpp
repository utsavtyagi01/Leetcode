class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stack;
        string ans;
        int i=0,temp=0;
        while(i<s.size()){
            if(s[i]=='(')
            {
                stack.push(s[i]);
                if(temp==0)
                {
                    temp++;
                    i++;
                    continue;
                }
                ans.push_back(s[i]);
            }
            else{
                ans.push_back(s[i]);
                stack.pop();
                if(stack.empty()){
                    temp=0;
                    ans.pop_back();
                }
            }
            i++;
        }
        return ans;
        
    }
};
