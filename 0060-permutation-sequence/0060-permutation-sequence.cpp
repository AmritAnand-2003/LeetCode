class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        set<int> numbers;
        for(int i = 1;i < n;i++){
            fact *= i;
            numbers.insert(i);
        }
        numbers.insert(n);
        string ans = "";
        k = k - 1;
        while(true){
            auto it = next(numbers.begin(), k/fact);
            ans += to_string(*it);
            numbers.erase(it);
            if(ans.size() == n){
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};