class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size(), COLS = matrix[0].size();
        int top = 0, bot = ROWS-1;

        while (top <= bot) {
            int mid = top + (bot-top)/2;

            if (matrix[mid][COLS-1] < target) {
                top = mid + 1;
            } else if (target < matrix[mid][0]) {
                bot = mid -1;
            } else {
                break;
            }
        }

        if (top > bot) {
            // Number didn't exist in ranges
            return false;
        }

        int l = 0, r = COLS-1, row = top + (bot-top)/2;
        
        while (l<=r) {
            int m = l + (r-l)/2;

            if (matrix[row][m] < target) {
                l = m + 1;
            } else if (target < matrix[row][m]) {
                r = m - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
