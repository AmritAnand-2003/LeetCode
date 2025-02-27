class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        unordered_set<int> set(arr.begin(), arr.end());
        for(int i = 0;i < n - 2;i++){
            for(int j = i + 1;j < n - 1;j++){
                // int ind = j + 1, last = j, sec_last = i, count = 0;
                int cur = arr[j] + arr[i], prev = arr[j], len = 2;
                while(set.find(cur) != set.end()){
                    int temp = cur;
                    cur += prev;
                    prev = temp;
                    ans = max(ans, ++len);
                }
                // while(ind < n){
                //     if(arr[ind] == arr[last] + arr[sec_last]){
                //         count++;
                //         sec_last = last;
                //         last = ind;
                //     }
                //     ind++;
                // }
                // ans = max(ans, count);
            }
        }
        return ans > 2 ? ans : 0;
    }
};