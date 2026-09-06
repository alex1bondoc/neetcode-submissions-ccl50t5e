class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<int[]> st = new Stack<>();
        int res = 0;

        int n = heights.length;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int start = i;
            while (st.size() > 0 && st.peek()[1] >= height) {
                int[] help = st.pop();
                int index = help[0];
                int h = help[1];
                res = Math.max(res, h * (i - index));
                start = index;
            }
            st.push(new int[]{start, height});
        }
        while (st.size() > 0) {
            int[] help = st.pop();
            int index = help[0];
            int h = help[1];
            res = Math.max(res, h * (n - index));
        }
        return res;
    }
}
