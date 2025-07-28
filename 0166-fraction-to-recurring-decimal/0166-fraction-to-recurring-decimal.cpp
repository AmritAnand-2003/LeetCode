class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        if(numerator == 0){
            return "0";
        }
        if((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }
        long long n = abs((long long)numerator), d = abs((long)denominator);
        long long val = n/ d;
        ans += to_string(abs(val));
        long long rem = abs(n % d);
        
        if(rem == 0){
            return ans;
        }
        ans += ".";
        unordered_map<long long, int> seen;
        while(rem != 0){
            // cout<<rem<<endl;
            if(seen.find(rem) != seen.end()) {
                ans.insert(seen[rem], "(");
                ans += ")";
                break;
            }
            seen[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;
        }
        return ans;
    }
};