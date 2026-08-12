class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        int i=0,j=0;
        bool turn = true;
        while (true) {
            if (i == word1.size()) {
                merged += word2.substr(j);
                break;
            }
            if (j == word2.size()) {
                merged += word1.substr(i);
                break;
            }
            if (turn) {
                merged += word1[i];
                i++;
                turn = !turn;
            } else {
                merged += word2[j];
                j++;
                turn = !turn;
            }
        }

        return merged;
    }
};