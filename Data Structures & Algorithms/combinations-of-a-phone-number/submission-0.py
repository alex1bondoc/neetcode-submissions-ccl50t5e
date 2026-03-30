class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        dic = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "qprs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(k, string):
            if k == len(digits):
                res.append(string)
                return
            aux = dic[digits[k]]
            for c in aux:
                backtrack(k + 1, string + c)


        if digits:
            backtrack(0, "")
            
        return res