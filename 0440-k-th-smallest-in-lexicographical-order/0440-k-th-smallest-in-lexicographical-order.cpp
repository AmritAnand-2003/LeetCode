class Solution {
public:
    int nodeCount(long n, long n1, long n2){
        int cnt = 0;
        while(n1 <= n){
            cnt += min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        long cur = 1;
        k--;
        while(k > 0){
            int cnt = nodeCount(n, cur, cur + 1);
            cout<<cnt<<" "<<k<<endl;
            if(k < cnt){
                cur *= 10;
                k--;
            }
            else{
                cur += 1;
                k -= cnt;
            }
        }
        return cur;
    }
};