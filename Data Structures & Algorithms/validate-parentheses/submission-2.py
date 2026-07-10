class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            else :
                if c == ')' and stack[-1] != '(':
                    return False 
                elif c == ']' and stack[-1] != '[':
                    return False 
                elif c == '}' and stack[-1] != '{':
                    return False 
                else :
                    stack.pop()
        isEmpty = not bool(stack)
        return isEmpty