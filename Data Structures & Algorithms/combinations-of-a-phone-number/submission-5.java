class Solution {
    private final String[] digitToChar = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "qprs", "tuv", "wxyz"
        };
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        StringBuilder cur = new StringBuilder();
        if (digits.length() == 0) return new ArrayList<>();
        back(res, digits, 0, cur);

        return res;
    }
    private void back(List<String> res, String digits, int index, StringBuilder cur) {
        if (index == digits.length()) {
            String combination = new String(cur);
            res.add(combination);
            return;
        }
        int i = (digits.charAt(index) - '0');
        for (char c : digitToChar[i].toCharArray()) {

            back(res, digits, index + 1, new StringBuilder(cur).append(c));
        }
    }
}
