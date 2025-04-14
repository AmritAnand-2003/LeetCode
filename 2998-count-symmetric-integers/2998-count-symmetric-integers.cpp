class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low;i <= high;i++){
            string cur = to_string(i);
            if(cur.size() % 2 == 0){
                int len = cur.size();
                int cur_sum = 0;
                for(int j = 0;j < len/2;j++){
                    // if(cur[j] != cur[len - 1 - j]){
                    cur_sum += (cur[j] - '0');
                    cur_sum -= (cur[len - 1 - j] - '0');
                    // }
                }
                if(cur_sum == 0){
                    count++;
                }
            }
        }
        return count;
    }
};