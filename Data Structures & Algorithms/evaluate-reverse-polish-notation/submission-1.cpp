class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (const auto& token: tokens) {
            if (isOperator(token)) {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                operands.push(evaluateOperation(a,b,token));
            } else {
                operands.push(stoi(token));
            }
        }

        return operands.top();
    }

    int evaluateOperation(int a, int b, string op) {
        if (op == "+") {
            return a + b;
        } else if (op == "-") {
            return a - b;
        } else if (op == "*") {
            return a * b;
        } 
        return floor(a / b);
    }

    bool isOperator(string op) {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }
};
