class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def back(o, c, cur):
            if o == 0 and c == 0:
                res.append("".join(cur))
                return
            elif o < 0 or o > c:
                return
            cur.append("(")
            back(o - 1, c, cur)
            cur.pop()
            cur.append(")")
            back(o, c - 1, cur)
            cur.pop()
        back(n, n, [])
        return res
