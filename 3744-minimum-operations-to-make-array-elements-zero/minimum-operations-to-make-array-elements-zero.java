class Solution {
    private long stepSum(long num) {
        long cnt = 0;
        int step = 1, base = 1;
        while(base <= num) {
            long cur = Math.min(num, base * 4 - 1) - base + 1;
            cnt  += cur * step;
            base *= 4;
            step++;
        }
        return cnt;
    }
    public long minOperations(int[][] queries) {
        long ans = 0;
        for(int[] q : queries) {
            long l = q[0], r = q[1];
            long total = stepSum(r) - stepSum(l - 1);
            ans += (total + 1) / 2;
        }
        return ans;
    }
}