class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        // vector<long > hidden(n + 1);
        int mn = 0, mx = 0;
        long cur = 0;
        for(int i = 0;i < n;i++){
            cur += differences[i] ;
            mn = min((long)mn, cur);
            mx = max((long)mx, cur);
        }
        // int mn = *min_element(hidden.begin(), hidden.end());
        // int mx = *max_element(hidden.begin(), hidden.end());
        // cout<<mx<<" "<<mn<<endl;
        int ans = (upper - lower) - (mx - mn) + 1;
        return ans > 0 ? ans : 0;
    }
};