class Solution {
public:
    int maxDepth(string s) {
        if(s.size()==0)
        return 0;
        int count = 0 , max= 0 ;
        for(auto &it:s){
            if(it=='(')
            count++;
            else if(it==')'){
                max=std::max(max,count);
                count--;

            }
        }
        return max;
    }
};
