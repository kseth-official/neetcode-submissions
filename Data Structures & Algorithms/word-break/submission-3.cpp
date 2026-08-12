class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int,vector<string>> lenMap;
        unordered_map<string, bool> canBeSegmented;

        int smallest = 1;
        for (const auto& s: wordDict) {
            lenMap[s.size()].push_back(s);
            if (s.size() < smallest)
                smallest = s.size();
            canBeSegmented.insert({s, true});
        }

        return helper(s, lenMap, canBeSegmented, smallest);
    }

    bool helper(string& s, unordered_map<int, vector<string>>& lenMap, unordered_map<string, bool>& canBeSegmented, int smallest) {
        if (canBeSegmented[s]) {
            return true;
        }

        if (s.size() < smallest) {
            return false;
        }
        bool result = false;
        for (int i=smallest;i<=s.size();i++) {
            if (lenMap.count(i) == 0) 
                continue;

            string curr = s.substr(0,i);
            vector<string>& possibleWords = lenMap[i];
            for (int j=0;j<possibleWords.size();j++) {
                if (curr == possibleWords[j]) {
                    string rest = s.substr(i);
                    if (canBeSegmented.count(rest) > 0) {
                        result |= canBeSegmented[rest];
                        continue;
                    }
                    bool currResult = helper(rest, lenMap, canBeSegmented, smallest);
                    canBeSegmented[rest] = currResult;
                    result |= currResult;
                }
            }
        }

        return result;
    }
};