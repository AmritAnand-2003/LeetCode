class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int ans = 0;
        int l = 0, r = n - 1;
        while(l < r) {
            int cur = (r - l) * Math.min(height[l], height[r]);
            ans = Math.max(ans, cur);
            if(height[l] > height[r]) {
                r--;
            }
            else {
                l++;
            }
        }
        return ans;
    }
}