class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto& x : asteroids){
            while(x < 0){
                if(st.empty() || st.top() < 0){
                    st.push(x);
                    break;
                }
                else if(abs(x) > st.top()){
                    st.pop();
                }
                else if( abs(x) == st.top()){
                    st.pop();
                    break;
                }
                else{
                    break;
                }
            }
            if(x > 0){
                st.push(x);
            }
        }
        vector<int> rem;
        while(!st.empty()){
            rem.push_back(st.top());
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        return rem;
    }
};