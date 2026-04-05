class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> open = new Stack<>();
        Stack<Integer> star = new Stack<>();

        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch == '(') {
                open.push(i);
            }
            else if(ch == '*')
                star.push(i);
            else {
                if (open.empty() && star.empty()) return false;
                if (!open.empty()) open.pop();
                else star.pop();
            }
        }
        while (!open.empty() && !star.empty()){
            if (open.pop() >  star.pop())
                return false;
        }
        return open.empty();
    }
}
