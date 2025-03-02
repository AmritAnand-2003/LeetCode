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
            int pos = k/fact;
            auto it = next(numbers.begin(), pos);
            int cur_num = *it;
            ans += to_string(cur_num);
            // cout<<cur_num<<" "<<ans<<" "<<fact<<" "<<k<<" "<<k/fact<<endl;
            numbers.erase(it);
            // cout<<numbers.size()<<endl;
            if(ans.size() == n){
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};