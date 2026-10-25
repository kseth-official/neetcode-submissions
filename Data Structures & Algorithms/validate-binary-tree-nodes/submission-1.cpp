class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> pc(n, 0);

        for (int i=0;i<n;i++) {
            int l = leftChild[i];
            int r = rightChild[i];
            if (l != -1) {
                pc[l]++;
            }
            if (r != -1) {
                pc[r]++;
            }
        }

        int pIdx = 0;
        bool seen = false;
        for (int i=0;i<n;i++) {
            if (!seen && pc[i] == 0) {
                pIdx=i;
                seen = true;
                continue;
            }

            // > 1 node with no parents so not a tree
            if (pc[i] == 0)
                return false;
        }

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(pIdx);
        vis[pIdx]=true;
        int c = 1;

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            for (const auto& v: {leftChild[t], rightChild[t]}) {
                if (v == -1)
                    continue;
                // Found a cycle
                if (vis[v])
                    return false;
                vis[v]=true;
                c++;
                q.push(v);
            }
        }

        return c == n;
    }
};
