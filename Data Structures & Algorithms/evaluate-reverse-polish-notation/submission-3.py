class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for elem in tokens: 
            if elem == "+":
                x2 = stack.pop()
                x1 = stack.pop()
                sol = x1 + x2
                stack.append(sol)
            elif elem == "-":
                x2 = stack.pop()
                x1 = stack.pop()
                sol = x1 - x2
                stack.append(sol)
            elif elem == "*":
                x2 = stack.pop()
                x1 = stack.pop()
                sol = x1 * x2
                stack.append(sol)
            elif elem == "/":
                x2 = stack.pop()
                x1 = stack.pop()
                
                sol = int(x1 / x2)
                stack.append(sol)
            else :
                stack.append(int(elem))

        return stack.pop()