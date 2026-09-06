class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
       Deque<int[]> dq = new ArrayDeque<>();
       int[] res = new int[nums.length - k + 1];
       int l = 0;
       for (int r = 0; r < nums.length; r ++) {
            int num = nums[r];
            while (!dq.isEmpty() && dq.peekFirst()[0] < l) {
                dq.removeFirst();
            }
            while (!dq.isEmpty() && dq.peekLast()[1] < num) {
                dq.removeLast();
            }
            dq.push(new int[]{r, num});
            if (r >= k - 1) {
                res[l] = dq.peekLast()[1];
                l++;
            }
       }
       return res;
    }
}
