class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> flattened;
        for (int i=0;i<matrix.size();i++) {
            for (int j=0; j<matrix[0].size();j++) {
                flattened.push_back(matrix[i][j]);
            }
        }

        int l = 0, r = flattened.size()-1;
        
        while (l<=r) {
            int m = l + (r-l)/2;

            if (flattened[m] < target) {
                l = m + 1;
            } else if (target < flattened[m]) {
                r = m - 1;
            } else {
                return true;
            }
        }

        return false;

        /*
            m = 3
            n = 4
            target = 10

            l = {0,0}
            h = {0,3}

            while
                mid = {1,1}


        */
        // int m = matrix.size(), n = matrix[0].size();
        
        // pair<int,int> l = {0,0};
        // pair<int,int> h = {m-1,n-1};

        // while (l.first <= h.first) {
        //     if (l.first == h.first) {
        //         return binarySearchRow(l.first, matrix, target);
        //     }

        //     pair<int,int> mid = {(h.first-l.first)/2, (h.second-l.second)/2};

        //     if (target < matrix[mid.first][mid.second]) {
        //         h = {mid.first-1, n-1};
        //     } else if (target > matrix[mid.first][mid.second]) {
        //         l = {mid.first+1, 0};
        //     } else {
        //         return true;
        //     }
        // }

        // return false;
    }


    bool binarySearchRow(const int& row, const vector<vector<int>>& matrix, const int& target) {
        int l = 0, r = matrix[0].size()-1;
        
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
