class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> hash;
        for(int i = 1;i <= n;i++){
            string cur = to_string(i);
            int sum = 0;
            for(auto& x : cur){
                sum += (x - '0');
            }
            hash[sum]++;
        }
        int ans = 0, mx = -1;
        for(auto it : hash){
            if(it.second > mx){
                mx = it.second;
                ans = 1;
            }
            else if(it.second == mx){
                ans++;
            }
        }
        return ans;
    }
};