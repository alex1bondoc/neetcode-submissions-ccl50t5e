public class Solution {
    public int LargestRectangleArea(int[] heights) {
        int res = 0;
        Stack<int> stack = new Stack<int>();
        for (int i = 0; i <= heights.Length; i++) {
            while(stack.Count > 0 && (i == heights.Length || heights[stack.Peek()] >= heights[i])){
                int p = stack.Peek();
                stack.Pop();
                int h = heights[p];
                int w = 0;
                if(stack.Count == 0) w = i;
                else w = i - stack.Peek() - 1;
                if(h * w > res)
                    res = h * w; 
            }
            stack.Push(i);
        }
        return res;
    }
}
