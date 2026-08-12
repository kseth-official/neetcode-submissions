class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_k = 1, max_k = piles[0];

        for (const auto& pile: piles) {
            max_k = max(pile, max_k);
        }

        int best_k;
        while (min_k <= max_k) {
            int mid_k = min_k + (max_k-min_k)/2;

            if (isValidK(mid_k,piles,h)) {
                best_k = mid_k;
                max_k = mid_k-1;
            } else {
                min_k = mid_k+1;
            }
        }

        return best_k;
    }

    bool isValidK(const int& k, vector<int> piles, int h) {
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] % k == 0) {
                h -= piles[i]/k;
            } else {
                h -= (piles[i]/k + 1);
            }
            
            // while (piles[i] != 0) {
            //     piles[i] = max(piles[i] - k, 0);
            //     h--;
            // }
        }

        return h >= 0;
    }
};
