class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int k = s1.size();

        unordered_map<char,int> fq;
        unordered_map<char,int> wfq;

        for (int i=0;i<k;i++) {
            fq[s1[i]]++;
            wfq[s2[i]]++;
        }

        int l = 0;
        int r = k-1;

        while (r < s2.size()-1) {
            if (equate(fq, wfq))
                return true;
            
            wfq[s2[l]]--;
            if (wfq[s2[l]] == 0)
                wfq.erase(s2[l]);
            l++;
            r++;
            wfq[s2[r]]++;
        } 

        return equate(fq,wfq);
    }

    bool equate(const unordered_map<char,int>& a, unordered_map<char,int>& b) {
        for (const auto& p: a) {
            if (b.count(p.first) == 0)
                return false;
            if (b[p.first] != p.second)
                return false;
        }

        return true;
    }
};
