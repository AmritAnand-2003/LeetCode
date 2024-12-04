class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while(i < str1.size() && j < str2.size()){
            char next = (str1[i] == 'z' ? 'a' : str1[i] + 1);
            if(str1[i] == str2[j] || next == str2[j]){
                i++, j++;
            }
            else{
                i++;
            }
            cout<<i<<" "<<j<<" "<<next<<endl;
        }
        cout<<j<<endl;
        return j == str2.size();
    }
};