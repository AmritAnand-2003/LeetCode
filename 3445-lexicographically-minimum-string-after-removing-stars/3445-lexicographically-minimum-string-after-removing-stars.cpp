class Compare {
    public:
    bool operator()(const pair<char, int>& a, const pair<char, int>& b){
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
};

class Solution {
public:
    string clearStars(string s) {
        char low = 'z';
        string ans;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        vector<bool> del(s.size(), false);
        for(int i = 0;i < s.size();i++){
            char x = s[i];
            if(x == '*'){
                auto temp = pq.top();
                pq.pop();
                del[temp.second] = true;
            }
            else{
                // ans.push_back(x);
                pq.push({x, i});
                low = min(low, x);
            }
        }
        for(int i = 0;i < s.size();i++){
            if(s[i] != '*' && !del[i]){
                ans += s[i];
            }
        }
        return ans;
    }
};