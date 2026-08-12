class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Being explicit with the zero here for readability although default initialization would assign it as zero anyway
        vector<vector<int>> adj_list(numCourses);
        vector<int> in_visited(numCourses, 0);

        // Implementing Kahn's Algorithm for topological sorting
        for (const auto& prereq: prerequisites) {
            adj_list[prereq[1]].push_back(prereq[0]);
            in_visited[prereq[0]]++;
        }

        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (in_visited[i] == 0)
                q.push(i);
        }
        
        int finished = 0;
        while (!q.empty()) {
            int head = q.front();
            q.pop();

            finished++;
            for (const auto& neighbor: adj_list[head]) {
                in_visited[neighbor]--;

                if (in_visited[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return finished == numCourses;
    }
};
