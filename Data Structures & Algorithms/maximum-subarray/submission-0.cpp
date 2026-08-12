class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxStickers = nums[0];
        int currStickers = 0;
        
        for (const auto& stickerChange: nums) {
            currStickers = max(stickerChange, currStickers + stickerChange);
            maxStickers = max(maxStickers, currStickers);
        }

        return maxStickers;
    }
};
