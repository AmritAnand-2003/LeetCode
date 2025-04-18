class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string prev = countAndSay(n - 1);
        char cur = prev[0];
        int count = 1;
        string ans = "";
        for(int i = 1;i < prev.size();i++){
            if(prev[i] != cur){
                ans += (count + '0');
                ans += cur;
                cur = prev[i];
                count = 1;
            }
            else{
                count++;
            }
        }
        ans += (count + '0');
        ans += cur;
        return ans;
    }
};