class Solution {
    public static int countSetBits(long n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
    public int makeTheIntegerZero(int num1, int num2) {
        for(long k = 1;;k++) {
            long targetSum = num1 - k * num2;
            if(targetSum < 0){
                break;
            }
            if(targetSum >= k && countSetBits(targetSum) <= k){
                return (int)k;
            }
        }
        return -1;
    }
}