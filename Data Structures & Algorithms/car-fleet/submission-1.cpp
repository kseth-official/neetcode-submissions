class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs;
        for (int i=0; i < position.size();i++) {
            pairs.push_back({position[i], speed[i]});
        }
        // We sort so that if a car is closer to target than another, it will have a lower index in pairs
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        stack<pair<int,int>> fleets;

        for (const auto& curr : pairs) {
            if (fleets.empty()) {
                fleets.push(curr);
                continue;
            }

            auto top = fleets.top();
            
            
            float time_to_target_top = (float) (target - top.first) / (float) top.second;
            float time_to_target_curr = (float) (target - curr.first) / (float) curr.second;

            if (time_to_target_curr > time_to_target_top) {
                // If the fleet closer to the target will reach before the current fleet, the fleets will not merge
                // Therefore, curr will form a new fleet
                fleets.push(curr);
            }
        }

        return fleets.size();
    }

};

