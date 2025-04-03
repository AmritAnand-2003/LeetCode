class Solution {
    public long maximumTripletValue(int[] nums) {
        long res = 0, maxl = 0, maxd = 0;
        for(int a : nums){
            res = Math.max(res, 1L * maxd * a);
            maxd = Math.max(maxd, maxl - a);
            maxl = Math.max(maxl, a);
        }
        return res;
    }
}