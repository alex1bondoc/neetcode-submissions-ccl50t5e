class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] count = new int[26];
        int[] count2 = new int[26];
        int need = 0;
        for (char c : s1.toCharArray()) {
            if (count[c - 'a'] == 0) need ++;
            count[c - 'a']++;
        }
        int l = 0;
        for (int r = 0; r < s2.length(); r++) {
            char c = s2.charAt(r);
            count2[c - 'a']++;
            if (count2[c - 'a'] == count[c - 'a']) need --;
            else if (count2[c - 'a'] == count[c - 'a'] + 1) need ++;
            if (r >= s1.length()) {
                c = s2.charAt(l);
                count2[c - 'a']--;
                if (count2[c - 'a'] == count[c - 'a']) need --;
                else if (count2[c - 'a'] == count[c - 'a'] - 1) need ++;
                l++;
            }

            for (int a : count2) {
                System.out.print(a);

            }
            System.out.println(" ");
            if (need == 0) return true;
        }
        return false;

    }
}
