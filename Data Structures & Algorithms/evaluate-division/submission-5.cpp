class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // precompute a mapping of unique variable -> index
        unordered_map<string, int> m;
        int p=0;
        for (int i=0;i<equations.size();i++) {
            string ai = equations[i][0];
            string bi = equations[i][1];

            if (m.count(ai) == 0) {
                m[ai] = p;
                p++;
            }
            if (m.count(bi) == 0) {
                m[bi] = p;
                p++;
            }    
        }
        int n = m.size();

        vector<vector<double>> reachable(n, vector<double>(n, 0));
        // division is 0 not possible since values never 0. so if 0,
        // not reachable

        for (int i=0;i<equations.size();i++) {
            auto& eq = equations[i];
            auto& ai = eq[0];
            auto& bi = eq[1];
            reachable[m[ai]][m[bi]]=values[i];
            reachable[m[bi]][m[ai]]=1/values[i];
            reachable[m[ai]][m[ai]]=1.0;
            reachable[m[bi]][m[bi]]=1.0;
        }

        // applying floyd warshall to calculate reachability and value when reached
        for (int k=0;k<n;k++) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    if (reachable[i][j] == 0 && reachable[i][k] !=0 && reachable[k][j] != 0)
                    reachable[i][j] = reachable[i][k]*reachable[k][j];
                    // this works because we assume that there are no
                    // contradictions in the equations
                }
            }
        }

        vector<double> soln;
        for (auto& q: queries) {
            string& cj = q[0];
            string& dj = q[1];

            if (m.count(cj) == 0 || m.count(dj) == 0 || reachable[m[cj]][m[dj]] == 0)
                soln.push_back(-1.0);
            else
                soln.push_back(reachable[m[cj]][m[dj]]);
        }

        return soln;
    }
};