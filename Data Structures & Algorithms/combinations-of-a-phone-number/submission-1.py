class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        dic = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        def back(k, cur) :
            if k == len(digits):
                if cur: 
                    res.append("".join(cur.copy()))
                return 
            letters = dic[digits[k]]
            for letter in letters:
                cur.append(letter)
                back(k + 1, cur)
                cur.pop()
        back(0, [])
        return res