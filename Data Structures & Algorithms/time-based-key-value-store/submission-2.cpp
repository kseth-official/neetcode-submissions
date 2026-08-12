class TimeMap {
public:

    // key -> List[{value1, timestamp1}, {value2, timestamp2}, ...]
    // List is sorted by timestamp, with earliest timestamp first due to strict ordering of timestamps
    unordered_map<string, vector<pair<string,int>>> t_map;

    TimeMap() {
        
    }
    
    /*
        Time Complexity: O(1)
    */
    void set(string key, string value, int timestamp) {
        t_map[key].push_back({value, timestamp});
    }
    
    /*
        Time Complexity: O(logn), n = number of times set was called
    */
    string get(string key, int timestamp) {
        int l = 0, r = t_map[key].size()-1;

        while (l <= r) {
            int m = l + (r-l)/2;
            
            if (t_map[key][m].second < timestamp) {
                l = m+1;
            } else if (t_map[key][m].second > timestamp) {
                r = m-1;
            } else {
                return t_map[key][m].first;
            }
        }

        if (0 <= r && r <= t_map[key].size()-1) 
            return t_map[key][r].first;

        return "";
    }
};
