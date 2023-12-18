class Solution {
public:
    string help(int n){
        if(n==1){
            return "1";
        }
        string tmp=help(n-1);
        string x="";
        int ct=1;
        for(int i=0;i<tmp.size()-1;i++){
            if(tmp[i]==tmp[i+1]){
                ct++;
            }else{
                x+=(to_string(ct)+tmp[i]);
                ct=1;
            }
        }
        return (x+to_string(ct)+tmp[tmp.size()-1]);
    }

    string countAndSay(int n) {
        return help(n); 
    }
};
