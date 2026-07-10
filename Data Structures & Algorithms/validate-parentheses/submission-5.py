class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c == ')':
                if stack and stack.pop() != '(':
                    return False
            elif c == ']':
                if stack and stack.pop() != '[':
                    return False
            elif c == '}':
                if stack and stack.pop() != '{':
                    return False
            else :
                stack.append(c)

        if stack:
            return False
        return True