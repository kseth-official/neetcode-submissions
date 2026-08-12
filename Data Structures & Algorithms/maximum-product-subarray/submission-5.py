class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        result = minp = maxp = nums[0]

        for x in nums[1:]:
            candidates = (x, x*minp, x*maxp)
            maxp = max(candidates)
            minp = min(candidates)
            result = max(result, maxp)

        return result
        