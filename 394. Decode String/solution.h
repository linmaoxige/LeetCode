class Solution {
public:
    /*C++方法2-用栈实现 击败100%*/
    string decodeString(string s) {
        int len = s.size();
        int num = 0;
        stack<int> numstack;
        stack<string> strstack;
        string cur = "";
        string result = "";
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = 10 * num + s[i] - '0';
            }
            else if (s[i] == '[') {
                numstack.push(num);
                strstack.push(cur);
                num = 0;
                cur.clear();
            }
            else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
                cur += s[i];
            }
            else if (s[i] == ']') {
                int cnt = numstack.top();
                numstack.pop();
                for (int j = 0; j < cnt; j++) {
                    strstack.top() += cur;
                }
                cur = strstack.top();
                strstack.pop();
            }
        }
        result = result + cur;
        return result;
    }
};