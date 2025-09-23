class Solution {
    int[][] dp;
    public int oddEvenJumps(int[] arr) {
        int n = arr.length;
        dp = new int[2][n];
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        for(int i = n - 1; i >= 0; i--) {
            Integer oddKey = mp.ceilingKey(arr[i]);
            dp[0][i] = (oddKey == null) ? -1 : mp.get(oddKey);
            Integer evenKey = mp.floorKey(arr[i]);
            dp[1][i] = (evenKey == null) ? -1 : mp.get(evenKey);
            mp.put(arr[i], i);
        }
        // for(int i = 0; i< 2; i++) {
        //     for(int j = 0; j < n; j++){
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        int ans = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(solve(i, 0, n - 1) == n - 1){
                ans ++;
                // System.out.println(i);
            }
        }
        // for(int i = 0; i< 2; i++) {
        //     for(int j = 0; j < n; j++){
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        return ans;
    }

    private int solve(int ind, int step, int target) {
        if(ind == target || ind == -1) {
            return ind;
        }
        int next = dp[step % 2][ind];
        return dp[step % 2][ind] = solve(next, step + 1, target);
    }
}