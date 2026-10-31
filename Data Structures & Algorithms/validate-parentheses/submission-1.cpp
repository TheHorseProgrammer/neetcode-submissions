class Solution {
public:
    bool isValid(string s) {
        stack<char> p_st;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                p_st.push(c);
            } else {
                if (p_st.empty()) {
                    return false;
                }
                char e = p_st.top();
                if (e == '(' && c == ')' ||
                    e == '{' && c == '}' ||
                    e == '[' && c == ']') {
                    p_st.pop();
                } else {
                    return false;
                }
                
            }
        }

        return p_st.empty();
    }
};
