class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // monotonic stack?
        stack<int> s;

        for (int i=arr.size()-1;i>=0;i--) {
            if (s.empty() || arr[i]>=s.top())
                s.push(arr[i]);
        }

        for (auto& a: arr) {
            if (a != s.top()) {
                a = s.top();
                continue;
            }
            s.pop();
            if (!s.empty())
                a = s.top();
        }

        arr[arr.size()-1] = -1;

        return arr;
    }
};