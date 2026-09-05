class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> fq;

        for (int i=0;i<s.size();i++) {
            fq[s[i]]++;
        }
        
        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;

        for (auto& p: fq) {
            pq.push({p.second, p.first});
        }

        string result = "";
        queue<pair<int,char>> q;

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();

            if (result.empty()) {
                result += t.second;
                if (t.first - 1 != 0)
                    q.push({t.first-1, t.second});
                continue;
            }

            result+=t.second;
            if (!q.empty()){
                pq.push(q.front());
                q.pop();
            }

            if (t.first - 1 != 0)
                q.push({t.first-1, t.second});
            else if (!q.empty())
                q.pop();
        }

        if (result.size() != s.size())
            return "";

        return result;
    }
};