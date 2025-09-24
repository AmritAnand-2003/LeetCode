class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        boolean sign = false;
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            sign = true;
        }
        long num = Math.abs((long)numerator);
        long den = Math.abs((long)denominator);
        String ans = "";
        long quot = num / den;
        long rem = num % den;
        ans = String.valueOf(quot);
        if(sign) {
            ans = "-" + ans;
        }
        if(rem == 0) {
            return ans;
        }
        ans = ans + ".";
        HashMap<Long, Integer> mp = new HashMap<>();
        String dec = "";
        while(rem > 0) {
            // String cur = "";
            // rem *= 10;
            // mp.put(rem, dec.length() + 1);
            // if(rem < den) {
            //     rem *= 10;
            //     dec = dec + "0";
            // }
            if(mp.containsKey(rem)){
                dec = dec.substring(0, mp.get(rem)) + "(" + dec.substring(mp.get(rem)) + ")";
                break;
            }
            mp.put(rem, dec.length());
            rem *= 10;
            quot = rem / den;
            rem = rem % den;
            dec = dec + String.valueOf(quot);
        }
        return ans + dec;
    }
}