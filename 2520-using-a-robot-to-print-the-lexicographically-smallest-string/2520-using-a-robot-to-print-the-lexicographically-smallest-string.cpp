class Solution {
public:
    string robotWithString(string s) {
        map<char, int> freq;
        char mn_char = 'z';
        for(auto& x : s){
            freq[x]++;
            mn_char = min(x, mn_char);
        }
        stack<char> st;
        string ans;
        for(int i = 0;i < s.size(); i++){
            while(freq[mn_char] == 0){
                freq.erase(mn_char);
                mn_char = freq.begin()->first;
            }
            // cout<<mn_char<<endl;
            while(!st.empty() && st.top() <= mn_char){
                ans += st.top();
                st.pop();
            }
            if(s[i] > mn_char){
                st.push(s[i]);
            }
            else if(s[i] == mn_char){
                ans += s[i];
            }
            freq[s[i]]--;
        }
        while(!st.empty()){
            ans += st.top();
            // cout<<st.top()<<" ";
            st.pop();
        }
        return ans;
    }
};