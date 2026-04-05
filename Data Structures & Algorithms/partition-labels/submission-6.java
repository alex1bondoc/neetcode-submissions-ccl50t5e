class Solution {
    public List<Integer> partitionLabels(String s) {
        HashMap<Character, Integer> last = new HashMap<>();
        int i =0;
        for (char c : s.toCharArray()) {
            last.put(c, i);
            i ++;
        }
        int l = 0;
        int r = 0;
        ArrayList<Integer> res = new ArrayList<>();
        while (l < s.length()) {
            for (i= l; i<= r; ++i) {
                r = Math.max(last.get(s.charAt(i)), r);

            }
            res.add(r - l + 1);
            l = r + 1;
            r = l;
        }   
        return res;
    }
}
