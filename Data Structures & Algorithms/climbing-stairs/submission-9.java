class Solution {
    private static HashMap<Integer, Integer> cache= new HashMap<>();
    static{
    cache.put(0, 0);
    cache.put(1, 1);
    cache.put(2, 2);
    }
    public int climbStairs(int n) {
        if (cache.containsKey(n)) {
            return cache.get(n);
        }
        cache.put(n, climbStairs(n - 1) + climbStairs(n - 2));
        return cache.get(n);
    }
}
