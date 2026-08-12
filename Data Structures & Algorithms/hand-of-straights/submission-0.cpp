class Solution {
public:
bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize == 1)
            return true;
        
        if (hand.size() % groupSize != 0)
            return false;

        // Count frequency of each card
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        
        // Try to form groups starting from smallest available card
        while (!count.empty()) {
            int start = count.begin()->first;
            
            // Try to form a group of consecutive cards starting from 'start'
            for (int i = 0; i < groupSize; i++) {
                int needed = start + i;
                if (count[needed] == 0) {
                    return false;  // Can't form consecutive group
                }
                count[needed]--;
                if (count[needed] == 0) {
                    count.erase(needed);
                }
            }
        }
        
        return true;
    }
};
