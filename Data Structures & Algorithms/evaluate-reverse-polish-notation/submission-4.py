class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if ord('0') <= ord(token) <= ord('9'):
                stack.append(token)
            else :
                elem2 = int(stack.pop())
                elem1 = int(stack.pop())
                if token == '+':
                    stack.append(f"{elem1 + elem2}")
                elif token == '-':
                    stack.append(f"{elem1 - elem2}")
                elif token == '*':
                    stack.append(f"{elem1 * elem2}")
                else:
                    stack.append(f"{elem1 // elem2}")
        return int(stack[-1])