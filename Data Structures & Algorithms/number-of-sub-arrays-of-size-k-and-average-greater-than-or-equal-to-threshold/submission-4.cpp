class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;

        int l=0,r=k-1;

        float rs = 0;
        for (int i=0;i<k;i++) {
            rs += arr[i];
        }

        while (r < arr.size()-1) {
            float avg = rs / static_cast<float>(k);
            if (avg >= static_cast<float>(threshold))
                count++;

            rs -= arr[l];
            l++;
            r++;
            rs += arr[r];
        }

        if (rs / static_cast<float>(k) >= threshold)
            count++;

        return count; 
    }
};