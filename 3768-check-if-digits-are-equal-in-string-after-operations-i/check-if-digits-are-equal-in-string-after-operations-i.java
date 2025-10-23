class Solution {
    public boolean hasSameDigits(String s) {
        int n = s.length();
        while(s.length() > 2) {
            StringBuilder result = new StringBuilder();
            for (int j = 0; j < s.length() - 1; j++) {
                int a = s.charAt(j) - '0';
                int b = s.charAt(j + 1) - '0';
                int sum = (a + b) % 10;
                result.append(sum);
            }
            s = result.toString();
        }
        return s.charAt(0) == s.charAt(1);
    }
}