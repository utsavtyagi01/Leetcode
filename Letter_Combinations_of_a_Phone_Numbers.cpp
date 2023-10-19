map<int,vector<char>> m={
    {3,{'d','e','f'}},
    {2,{'a','b','c'}},
    {4,{'g','h','i'}},
    {5,{'j','k','l'}},
    {6,{'m','n','o'}},
    {7,{'p','q','r','s'}},
    {8,{'t','u','v'}},
    {9,{'w','x','y','z'}}
};
int n=0;
vector<string> ans;
vector<string> ans1;
string temp=""; 
void func(string &arr,int i){
    if(i==arr.size()){
        ans.push_back(temp);
        return;
    }
    for(char c:m[arr[i]-'0']){
        temp.push_back(c);
        func(arr,i+1);
        temp.pop_back();
    }
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> a;
        if(digits.size()==0)
        return a;
        func(digits,0);
        ans1=ans;
        ans.clear();
        return ans1;
        
    }
};
