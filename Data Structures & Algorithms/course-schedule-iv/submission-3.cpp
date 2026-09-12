class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        for (const auto& p: prerequisites) {
            reachable[p[0]][p[1]] = true;
        }

        // Using Floyd-Warshall to construct a transitive closure
        // over the reachability relation defined by prerequisites
        for (int k=0;k<numCourses;k++) {
            for (int i=0;i<numCourses;i++) {
                for (int j=0;j<numCourses;j++) {
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
                }
            }
        }

        vector<bool> soln;
        for (const auto& q: queries) {
            soln.push_back(reachable[q[0]][q[1]]);
        }

        return soln;
    }
};