class MinStack {
public:
    stack<int> main_stack;
    stack<int> min_stack;

    MinStack() {
        
    }
    
    void push(int val) {
        main_stack.push(val);

        if (min_stack.empty()) {
            min_stack.push(val);
        } else {
            min_stack.push(min(val, min_stack.top()));
        }
    }
    
    void pop() {
        main_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
