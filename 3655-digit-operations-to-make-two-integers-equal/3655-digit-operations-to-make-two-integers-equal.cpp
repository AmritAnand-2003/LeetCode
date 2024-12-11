class Solution {
public:
    bool prime(int n) {
    if (n <= 1) return false;     
    if (n <= 3) return true;     
    if (n % 2 == 0 || n % 3 == 0) return false; 
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

    // void solve(string n, unordered_map<int, int>& mp){
    //     int sz = s.size();
    //     int val = stoi(n);
    //     int ans = -1;
    //     if(mp.find(val)){
    //         return mp[val];
    //     }
    //     for(int i = 0;i < sz;i++){
    //         if(n[i] != '9'){
    //             string op1 = n;
    //             op1[i] += 1;
    //             if(!prime(stoi(op1)){
    //                 solve(op1, mp);
    //             }
    //         }
    //     }
    // }
    int minOperations(int n, int m) {
        if(prime(n) || prime(m)){
            return -1;
        }
        string sn = to_string(n);
        string sm = to_string(m);
        int sz = sn.size();
        unordered_map<int, int> mp;
        // mp[m] = -1;
        // mp[m] = m;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int , string>>> pq;
        pq.push({n, sn});
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            string num = cur.second;
            int cur_sum = cur.first;
            if(num == sm){
                return cur_sum;
            }
            // cout<<num<<" "<<cur_sum<<endl;
            for(int i = 0;i < sz;i++){
                // cout<<"child ";
                if(num[i] != '9'){
                    string op1 = num;
                    op1[i] += 1;
                    int op1Val = stoi(op1);
                    // cout<<op1Val<<" ";
                    if(mp[op1Val] == 0 && !prime(op1Val)){
                        pq.push({op1Val + cur_sum, op1});
                        mp[op1Val] = op1Val + cur_sum;
                    }
                }
                if(num[i] != '0' && (i != 0 || num[i] != '1')){
                    string op2 = num;
                    op2[i] -= 1;
                    int op2Val = stoi(op2);
                    // cout<<op2Val;
                    if(mp[op2Val] == 0 && !prime(op2Val)){
                        pq.push({op2Val + cur_sum, op2});
                        mp[op2Val] = op2Val + cur_sum;
                    }
                }
                // cout<<endl;
            }
        }
        return (mp[m] == 0 ? -1 : mp[m]);
    }
};