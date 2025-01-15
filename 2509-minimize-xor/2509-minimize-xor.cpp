class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int countBits2 = 0, countBits1 = 0;
        while(num2){
            countBits2 += num2 & 1;
            num2 >>= 1;
        }
        int num = num1, mul = 1;
        for(int i = 0;i < 32;i++){
            // cout<<num<<" "<<(1 << i)<<endl;
            if(num & (1 << i)){
                countBits1++;
            }
        }
        int pos = 0;
        while(countBits1 != countBits2){
            int cur = 1 <<pos;
            if(countBits1 > countBits2){
                if(num & cur){
                    num ^= cur;
                    countBits1--;
                }
            }
            else{
                if((num & cur) == 0){
                    num ^= cur;
                    countBits1++;
                }
            }
            pos++;
        }
        return num;
    }
};