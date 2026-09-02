class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pr;
    
        for (int i=0;i<words.size();i++) {
            auto& word = words[i];
            char& st = word[0];
            char& end = word[word.size()-1];

            int r = 0;
            if (isVowel(st) && isVowel(end)) {
                r = 1;
            } 
            
            if (pr.empty())
                pr.push_back(r);
            else
                pr.push_back(pr[i-1] + r);
        }     

        vector<int> result;
        for (int i=0;i<queries.size();i++) {
            int li = queries[i][0];
            int ri = queries[i][1];

            int k;
            if (li == 0)
                k = pr[ri];
            else 
                k = pr[ri]-pr[li-1];
            result.push_back(k);
        }

        // 1 0 1 1 1

        // 1 1 2 3 4

        // 4 3 3 2 1

        return result;
    }

    bool isVowel(char l) {
        return l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u';
    }
};