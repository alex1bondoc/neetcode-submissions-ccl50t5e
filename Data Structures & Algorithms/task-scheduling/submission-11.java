class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] chars = new int[26];
        int maxi = 0;
        int cnt = 0;
        for (char c : tasks){
            chars[c - 'A'] += 1;
            if (chars[c - 'A'] > maxi){
                maxi = chars[c - 'A'];
                cnt = 1;
            }
            else if(chars[c - 'A'] == maxi) {
                cnt += 1;
            }
        }
        return Math.max(tasks.length,(maxi - 1) * (n + 1) +cnt);

    }
}
