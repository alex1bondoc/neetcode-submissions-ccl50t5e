class Solution:

    def encode(self, strs: List[str]) -> str:
        rez = []
        for str in strs:
            newStr = f"{len(str)}#{str}"
            rez.append(newStr)
        return "".join(rez)

    def decode(self, s: str) -> List[str]:
        sol = []
        for i in range(len(s)):
            if ord(s[i]) < ord('9') and ord(s[i]) > ord('0') and s[i + 1] == '#':
                str1 = s[i+2 : i + 2 + (ord(s[i]) - ord('0'))]
                sol.append(str1)
                i += 2 + ord(s[i])
        
        return sol