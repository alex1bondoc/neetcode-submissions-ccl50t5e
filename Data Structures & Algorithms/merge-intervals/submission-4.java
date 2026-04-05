class Solution {
    public int[][] merge(int[][] intervals) {
        int maxi = 0;
        for (int[]  interval : intervals) {
            maxi = Math.max(interval[0], maxi);
        }
        int[] mp = new int[maxi + 1];
        for (int[] interval : intervals) {
            mp[interval[0]] = Math.max(mp[interval[0]], interval[1] + 1);
        }
        int have = -1;
        int start = -1;
        ArrayList<int[]> res = new ArrayList<>();
        for (int i = 0; i <= maxi; ++i) {
            if (mp[i] != 0) {
                if (start == -1) {
                    start = i;
                }
                    have = Math.max(mp[i] - 1, have);

            }
            if (i == have) {
                res.add(new int[]{start, have});
                have = -1;
                start = -1;
            }
        }
        if (start != -1) res.add(new int[]{start, have});
        return res.toArray(new int[res.size()][2]);
    }
}
