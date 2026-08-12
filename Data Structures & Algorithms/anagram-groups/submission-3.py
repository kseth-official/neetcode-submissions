class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = defaultdict(list)
        for str in strs:
            c = [0] * 26
            for x in str:
                c[ord(x) - ord('a')] += 1
            result[tuple(c)].append(str)
        
        return list(result.values())