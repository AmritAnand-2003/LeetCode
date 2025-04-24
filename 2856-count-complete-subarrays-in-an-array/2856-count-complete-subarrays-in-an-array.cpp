class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> st;
        for(auto& x : nums){
            st[x]++;
        }
        int cnt = st.size(), ans = 0;
        int left = 0, right = 0;
        st.clear();
        while(left < n){
            while(right < n && st.size() < cnt){
                st[nums[right]]++;
                right++;
            }
            if(st.size() == cnt){
                ans += n - right + 1;
            }
            st[nums[left]]--;
            if(st[nums[left]] == 0){
                st.erase(nums[left]);
            }
            left++;
        }
        return ans;

    }
};