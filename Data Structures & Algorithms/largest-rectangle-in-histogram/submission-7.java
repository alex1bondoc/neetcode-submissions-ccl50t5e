class Solution {
    public int largestRectangleArea(int[] heights) {
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i <= heights.length; i++) {
            while(!stack.empty() && (i == heights.length ||  heights[stack.peek()] >= heights[i])){
                int h = heights[stack.pop()];
                int w = 0;
                if (stack.empty()) w = i;
                else w = i - stack.peek() - 1;
                res = Math.max(res, h * w);
            }
            stack.push(i);
        }
        return res;
    }
}
