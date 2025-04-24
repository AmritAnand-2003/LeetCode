class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto& x : nums){
            st.insert(x);
        }
        int cnt = st.size(), ans = 0;
        for(int i = 0;i < n;i++){
            st.clear();
            for(int j = i; j < n;j++){
                st.insert(nums[j]);
                if(st.size() == cnt){
                    ans += n - j;
                    break;
                }
            }
        }
        return ans;

    }
};