class Solution:
    def partition(self, s: str) -> List[List[str]]:
        
        res = []
        def back(k, cur):
            print(cur)
            if k == len(s):
                res.append(cur.copy())
                return
            for i in range(k, len(s)):
                print(self.isPalindrom(s[k: i + 1]))
                if self.isPalindrom(s[k:i + 1]):
                    cur.append(s[k: i + 1])
                    back(i + 1, cur)
                    cur.pop()
        back(0, [])
        return res
    def isPalindrom(self, s):
            print(s)
            l = 0
            r = len(s) - 1
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True