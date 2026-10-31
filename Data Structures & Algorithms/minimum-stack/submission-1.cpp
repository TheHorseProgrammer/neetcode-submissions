class MinStack {
private:
    vector<int> stack_int{};
    vector<int> min_stack_int{};
public:
    MinStack() {
    }
    
    void push(int val) {
        if (min_stack_int.empty() || stack_int[*min_stack_int.rbegin()] > val) {
            min_stack_int.push_back(stack_int.size());   
        }
        stack_int.push_back(val);
        
    }
    
    void pop() {
        stack_int.pop_back();
        if (*min_stack_int.rbegin() >= stack_int.size()) {
            min_stack_int.pop_back();
        }
        cerr << "popped\n";
    }
    
    int top() {
        return *stack_int.rbegin();
    }
    
    int getMin() {
        return stack_int[*min_stack_int.rbegin()];
    }
};
