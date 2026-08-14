class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l=0, r=k-1;
        float avg_so_far = 0;
        float running_sum = 0;
        for (int i=0;i<k;i++) {
            running_sum+= arr[i];
        }
        avg_so_far = running_sum / k;
        int count = 0;
        if (avg_so_far >= threshold)
            count++;
        
        while (r < arr.size()-1) {
            running_sum -= arr[l];
            l++;
            r++;
            running_sum += arr[r];

            if (running_sum / k >= threshold)
                count++;
        }

        return count;
    }
};