class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        
        for (int i=0;i<operations.size();i++) {
            const string& operation = operations[i];
            if (operation == "+") {
                int last = record.top();
                record.pop();
                int secLast = record.top();
                record.push(last);
                record.push(last+secLast);
            } else if (operation == "D") {
                record.push(record.top() * 2);
            } else if (operation == "C") {
                record.pop();
            } else {
                record.push(stoi(operation));
            }
        }

        int sum = 0;
        while (!record.empty()) {
            sum += record.top();
            record.pop(); 
        }

        return sum;
    }
};