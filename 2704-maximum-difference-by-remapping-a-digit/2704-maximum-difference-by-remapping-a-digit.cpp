class Solution {
public:
    int minMaxDifference(int num) {
        // int digits = log10(num);
        // int last_dig = num / (int)(pow(10, digits));
        // cout<<last_dig<<endl;
        char last_dig_mx = '#', last_dig_mn = '#';
        string num_str = to_string(num);
        string num_mx, num_mn;
        for(auto x : num_str){
            if(last_dig_mx == '#' && x != '9'){
                last_dig_mx = x;
            }
            if(last_dig_mn == '#' && x != '0'){
                last_dig_mn = x;
            }
            char a = x, b = x;
            if(x == last_dig_mx){
                a = '9';
            }
            if(x == last_dig_mn){
                b = '0';
            }
            num_mx += a;
            num_mn += b;
        }
        // cout<<last_dig_mx<<" "<<last_dig_mn<<endl;
        // cout<<num_mx<<" "<<num_mn<<endl;
        return stoi(num_mx) - stoi(num_mn);
    }
};