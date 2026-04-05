class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) {
            return false;
        }
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int num : hand) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        for (int num: hand) {
            if (count.get(num) != 0) {
                int start = num;
                while (count.getOrDefault(start - 1, 0) != 0) {
                    start = start - 1;
                }
                for (int i = 0; i < groupSize; ++i) {
                    if (count.getOrDefault(i + start, 0) == 0) {
                        return false;
                    }
                    count.put(i + start, count.get(i + start) - 1);
                }
            }
        }
        return true;
    }
}
