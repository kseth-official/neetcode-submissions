class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { 
        unordered_map<string,vector<string>> l;

        int n = wordList.size();

        for (const auto& s: wordList) {
            if (replaceDistOne(beginWord, s))
                l[beginWord].push_back(s);
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (replaceDistOne(wordList[i], wordList[j])) {
                    l[wordList[i]].push_back(wordList[j]);
                    l[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // Perform a bfs starting from beginWord over adjacency list
        // Since undirected graph with equal weights, if node found on bfs
        // it's distance is shortest
        queue<pair<string,int>> q;
        unordered_set<string> seen;

        // start at 1 since we're counting min words in transform sequence
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [s, d] = q.front();
            q.pop();

            // don't cycle in graph
            if (seen.count(s) > 0)
                continue;
            
            seen.insert(s);

            for (const auto& n: l[s]) {
                if (n == endWord)
                    return d+1;
                q.push({n, d+1});
            }
        }

        return 0;
    }

    bool replaceDistOne(const string& a, const string& b) {
        // We can't transform a to b by replacing 1 char
        // if diff lengths
        // we consider equal strings as not at a replace distance of 1
        if (a.size() != b.size() || a == b)
            return false;

        int n = a.size();

        bool seen = false;
        // check exactly one mismatch in O(n)
        for (int i=0;i<n;i++) {
            if (a[i] != b[i] && !seen)
                seen = true;
            else if (a[i] != b[i] && seen)
                return false;
        }

        return true;
    }
};
