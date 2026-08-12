class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for idx, num in enumerate(nums):
            mp[num]=idx
        for idx, num in enumerate(nums):
            diff = target-num
            if diff in mp and idx != mp[diff]:
                idy = mp[diff]
                return [idx, idy] if idx < idy else [idy, idx]
        
        # We should not get here...
        return []