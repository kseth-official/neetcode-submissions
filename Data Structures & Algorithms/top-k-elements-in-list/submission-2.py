class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = defaultdict(int)
        for n in nums:
            mp[n]+=1
        heap = list((-value, key) for key, value in mp.items())
        heapq.heapify(heap)
        result = []
        for i in range(k):
            result.append(heapq.heappop(heap)[1])
        return result