class Solution {
public:
    char kthCharacter(int k) {
        string cur = "a";
        while(cur.size() < k){
            string next = cur;
            for(auto& x: next){
                if(x == 'z'){
                    x = 'a';
                }
                else{
                    x++;
                }
            }
            cur = cur + next;
        }
        return cur[k - 1];
    }
};