class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        cur = []
        def backtrack(o, c):
            if o == 0 and c == 0:
                res.append("".join(cur))
                return
            if c < o:
                return 
            if o > 0:
                cur.append("(")
                backtrack(o - 1, c)
                cur.pop()
            if c > 0:
                cur.append(")")
                backtrack(o, c - 1)
                cur.pop()


        backtrack(n, n)

        return res