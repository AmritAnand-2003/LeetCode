class Solution {
public:
    string breakPalindrome(string palindrome) {
        int ind = -1;
        int i = 0;
        int n = palindrome.size();
        for(;i < n;i++){
            if(i < (n)/2){
                if(palindrome[i] != 'a'){
                    ind = i;
                    palindrome[i] = 'a';
                    break;
                }
            }
            else if(i >= (n + 1)/2){
                int st = (n + 1) / 2;
                int j = n - 1 - (i - st);
                cout<<j<<endl;
                if(palindrome[j] != 'z'){
                    // cout<<"Inside"<<endl;
                    ind = i;
                    palindrome[j] += 1;
                    break;
                }
            }
        }
        if(ind == -1){
            return "";
        }
        return palindrome;
    }
};