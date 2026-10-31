class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ret(n);
        stack<int> elem_stack;
        for (int i = 0; i < n; i++) {
            while (!elem_stack.empty() &&temperatures[elem_stack.top()] < temperatures[i]) {
                ret[elem_stack.top()] = i - elem_stack.top();
                elem_stack.pop();
            }
            elem_stack.push(i);
        }
        while (!elem_stack.empty()) {
            ret[elem_stack.top()] = 0;
            elem_stack.pop();
        }
        return ret;
    }
};
