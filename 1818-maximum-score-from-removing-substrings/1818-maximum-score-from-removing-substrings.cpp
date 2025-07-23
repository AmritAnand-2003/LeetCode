class Solution {
public:
    int solve(string& s, string match, int val){
        int ans = 0;
        stack<char> st;
        for(int i = 0;i < s.size();i++){
            if(s[i] == match[1] && !st.empty() && st.top() == match[0]){
                ans += val;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string temp = "";
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;
        return ans;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if(x > y){
            ans += solve(s, "ab", x);
            ans += solve(s, "ba", y);
        }
        else{
            ans += solve(s, "ba", y);
            ans += solve(s, "ab", x);
        }
        cout<<s<<endl;
        return ans;
    }
};