class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if ord('0') <= ord(token[0]) <= ord('9'):
                stack.append(token)
            else :
                if len(stack) < 2 :
                    return
                elem2 = int(stack.pop())
                elem1 = int(stack.pop())
                if token == '+':
                    stack.append(f"{elem1 + elem2}")
                elif token == '-':
                    stack.append(f"{elem1 - elem2}")
                elif token == '*':
                    stack.append(f"{elem1 * elem2}")
                else:
                    stack.append(f"{int(elem1 / elem2)}")
        return int(stack[0])