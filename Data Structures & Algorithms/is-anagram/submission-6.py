class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        count = {}

        for c1, c2 in zip(s,t):
            if c1 in count:
                count[c1]+=1
            else:
                count[c1]=1
            if c2 in count:
                count[c2]-=1
            else:
                count[c2]=-1

        return all(value == 0 for value in count.values())