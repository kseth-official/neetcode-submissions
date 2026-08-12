class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
            1. T: O(nk - k^2), S: O(max(k,n-k)) solution - using max heap and heapifying
            each window in O(k) time for a total n-k windows, with total
            equal to k*(n-k). 

            Suppose we define a window of size k where

            2 = 1st largest
            1 = 2nd largest
            1 = 3rd largest

            we increment window indices i, j by 1 to indicate moving the window forward,
            where i, j start at 0

            1 gets removed, 0 gets added to the window
            We find a mapping of 1 to what largeness rank it has in the window 
            (in this case 3 and 2, sorted in decreasing order, so we just check the first 
            index to find the smallest largeness ranking of 1 which is 3 - 3rd largest)

            Now we look at the next number and try to find its relative largeness rank, i.e., how does 0
            compare to 2, 1, and 1 in the previous window

            we can maintain 2 maps, number to largeness rank and largeness rank to number

            3rd largest is 1 found efficiently using the largeness rank to number map
        */

            vector<int> maxElementsInWindows;

            int i = 0, j = 0 + k - 1; // 0 indicates index i more generally for length plus start index calculations
            multiset<int, greater<int>> window(nums.begin() + i, nums.begin() + j + 1);
            while (j < nums.size()) {
                int largest = *window.begin();
                maxElementsInWindows.push_back(largest);
                window.erase(window.find(nums[i]));
                i++;
                j++;
                if (j < nums.size()) 
                    window.insert(nums[j]);
            }

            return maxElementsInWindows;
    }
};
