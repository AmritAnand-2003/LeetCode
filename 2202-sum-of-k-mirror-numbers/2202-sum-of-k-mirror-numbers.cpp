class Solution {
public:
    bool isPalindrome(string num){
        int len = num.size();
        for(int i = 0;i < len/2;i++){
            if(num[i] != num[len - 1 - i]){
                return false;
            }
        }
        return true;
    }
    bool is_basek_palindrome(long num, int k){
        string digits;
        while(num > 0){
            int dig = num % k;
            digits = char(dig + '0') + digits;
            num /= k;
        }
        return isPalindrome(digits);
    }
    long long kMirror(int k, int n) {
        int cnt = 0;
        long long ans = 0;
        int left = 1;
        while(cnt < n){
            int right = left * 10;
            for(int op = 0; op < 2;op++){
                for(int i = left; i < right && cnt < n;i++){
                    long long cur = i;
                    // cout<<cur<<" ";
                    int x = (op == 0 ? i / 10 : i);
                    while(x){
                        cur = cur * 10 + x % 10;
                        x /= 10;
                    }
                    // cout<<cur<<endl;
                    if(is_basek_palindrome(cur, k)){
                        cnt++;
                        ans+= cur;
                    }
                }
            }
            left = right;
        }
        return ans;
    }
};