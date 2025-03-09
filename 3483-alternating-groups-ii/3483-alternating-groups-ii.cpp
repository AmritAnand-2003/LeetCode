class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), i = 0, ans = 0;
        while(i < n){
            int cur = i;
            while(cur < n - 2 + k && colors[cur % n] != colors[(cur + 1) % n]){
                cur++;
            }
            if(cur - i + 1 >= k){
                ans += (cur - i + 2 - k);
            }
            i = cur + 1;
        }
        return ans;
    }
};