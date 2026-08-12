class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count = {}
        p = len(s)
        q = len(t)
        if p > q:
            t += ' ' * (p-q)
        else:
            s += ' ' * (q-p)

        for c1, c2 in zip(s,t):
            if c1 not in count:
                count[c1]=1
            else:
                count[c1]+=1
            if c2 not in count:
                count[c2]=-1
            else:
                count[c2]-=1

        return all(value == 0 for value in count.values())