class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs;
        for (int i=0; i < position.size();i++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        stack<pair<int,int>> fleets;

        for (const auto& pair : pairs) {
            if (fleets.empty()) {
                fleets.push(pair);
                continue;
            }

            auto top = fleets.top();
            
            float time_to_target_top = (float) (target - top.first) / (float) top.second;
            float time_to_target_curr = (float) (target - pair.first) / (float) pair.second;

            if (time_to_target_curr > time_to_target_top) {
                // Curr will form a new fleet
                fleets.push(pair);
            }
        }

        return fleets.size();
    }

};

