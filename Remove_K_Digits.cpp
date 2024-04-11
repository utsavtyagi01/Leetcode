class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        
        for (int i = 0; i < num.size(); i++) {
            while (!s.empty() && k > 0 && s.top() > num[i]) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while (k > 0) {
            s.pop();
            k--;
        }
        string result;
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());
        int startIndex = 0;
        while (startIndex < result.size() && result[startIndex] == '0') {
            startIndex++;
        }
        return startIndex == result.size() ? "0" : result.substr(startIndex);
    }
};
