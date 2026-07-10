class Solution:

    def encode(self, strs: List[str]) -> str:
        res = []
        for string in strs:
            res.append(f"{len(string)}#")
            res.append(string)
        return "".join(res)
    def decode(self, s: str) -> List[str]:
        print(s)
        res = []
        i, nr, pow = 0, 0, 1
        while i < len(s):
            if s[i] != '#':
                nr += nr * 10 + (ord(s[i]) - ord("0"))
            else:
                if i + 1 + nr == i + 1:
                    res.append("")
                else :
                    res.append(s[i + 1: i + 1 + nr])
                i += nr
                nr, pow = 0, 1
            i += 1
        return res