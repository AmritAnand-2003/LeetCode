class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0, n = A.size();
        vector<int> ans;
        unordered_map<int, int> pres_a, pres_b;
        for(int i = 0;i < n;i++){
            if(A[i] == B[i]){
                count++;
            }
            else{
                if(pres_b[A[i]] > 0){
                    pres_b[A[i]]--;
                    count++;
                }
                else{
                    pres_a[A[i]]++;
                }
                if(pres_a[B[i]] > 0){
                    pres_a[B[i]]--;
                    count++;
                }
                else{
                    pres_b[B[i]]++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};