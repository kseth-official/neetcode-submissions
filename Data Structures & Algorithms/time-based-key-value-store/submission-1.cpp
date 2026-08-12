class TimeMap {
public:

    // key -> List[{value1, timestamp1}, {value2, timestamp2}, ...]
    // List is sorted by timestamp, with earliest timestamp first due to strict ordering of timestamps
    unordered_map<string, vector<pair<string,int>>> t_map;

    // key -> HashSet[timestamp1, timestamp2, ...]
    // Stores all seen timestamps till now
    unordered_map<string, unordered_set<int>> e_t_map;

    /*
    
    */
    TimeMap() {
        
    }
    
    /*
        Time Complexity: O(1)
    */
    void set(string key, string value, int timestamp) {
        t_map[key].push_back({value, timestamp});
        e_t_map[key].insert(timestamp);
    }
    
    /*
        Time Complexity: O(1000 + logn), n = number of times set was called
    */
    string get(string key, int timestamp) {
        int prev_timestamp = find_previous_timestamp(key, timestamp);

        if (prev_timestamp == -1) {
            return "";
        }

        return find_value_at_timestamp(key, prev_timestamp);
    }

    int find_previous_timestamp(const string& key, const int& timestamp) {
        int l = 1, r = timestamp;
        
        for (int r = timestamp; r >= 1; r--) {
            auto set = e_t_map[key];
            if (set.find(r) != set.end())
                return r;
        }

        return -1;
    }

    string find_value_at_timestamp(const string& key, const int& timestamp) {
        int l = 0, r = t_map[key].size()-1;
        
        string value = "";

        while (l <= r) {
            int m = l + (r-l)/2;
            
            if (t_map[key][m].second < timestamp) {
                l = m+1;
            } else if (t_map[key][m].second > timestamp) {
                r = m-1;
            } else {
                value = t_map[key][m].first;
                break;
            }
        }

        return value;
    }
};
