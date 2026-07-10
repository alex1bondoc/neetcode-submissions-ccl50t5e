class Solution {
    public int tribonacci(int n) {
        int one = 0, two = 0, three = 1;
        for (int i = 0; i < n - 1; ++i) {
            int temp = three + two + one;
            one = two;
            two = three;
            three = temp;
        }
        return three;
    }
}