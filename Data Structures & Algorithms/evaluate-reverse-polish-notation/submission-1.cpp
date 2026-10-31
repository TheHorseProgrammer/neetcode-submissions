class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> exec_stack;
        for (string& token_str: tokens) {
            if (token_str.size() > 1) {
                exec_stack.push(stoi(token_str));
                continue;
            }
            char token = token_str[0];
            if (token >= '0' && token <= '9') {
                exec_stack.push(token - '0');
            } else {
                int r = exec_stack.top();
                exec_stack.pop();
                int l = exec_stack.top();
                exec_stack.pop();
                int result;
                switch (token) {
                    case '+':
                        result = l + r;
                        break;
                    case '-':
                        result = l - r;
                        break;
                    case '*':
                        result = l * r;
                        break;
                    case '/':
                        result = l / r;
                        break;
                    default:
                        return -1000000;
                }
                exec_stack.push(result);
            }
        }
        return exec_stack.top();
    }
};
