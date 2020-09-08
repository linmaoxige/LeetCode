class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] <= 'Z' && str[i]>='A') {
                str[i] = char(str[i] + 32);
            }
        }
        return str;
    }
};