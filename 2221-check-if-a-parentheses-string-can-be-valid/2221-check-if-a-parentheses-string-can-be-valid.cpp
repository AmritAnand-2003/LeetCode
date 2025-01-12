class Solution {
public:
    bool canBeValid(string s, string locked) {
        int open_count = 0;
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(locked[i] == '1'){
                open_count += (s[i] == '(' ? 1 : 0);
            }
        }
        // cout<<open_count<<endl;
        int dif = 0;
        for(int i = 0;i < n;i++){
            if(locked[i] == '0'){
                if(open_count < n/2){
                    s[i] = '(';
                    open_count++;
                }
                else{
                    s[i] = ')';
                }
            }
            dif += (s[i] == '(' ? 1 : -1);
            // cout<<s[i]<<" "<<open_count<<"  ";
            if(dif < 0){
                return false;
            }
        }
        return dif == 0;
    }
};