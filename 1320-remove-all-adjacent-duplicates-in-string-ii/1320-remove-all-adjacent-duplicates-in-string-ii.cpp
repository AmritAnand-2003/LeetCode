class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(auto& x : s){
            if(st.empty() || st.top().first != x){
                st.push({x, 1});
            }
            else{
                auto cur = st.top();
                st.pop();
                cur.second++;
                if(cur.second < k){
                    st.push(cur);
                }
            }
        }
        string ans;
        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            for(int i = 0;i < cur.second; i++){
                ans += cur.first;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};