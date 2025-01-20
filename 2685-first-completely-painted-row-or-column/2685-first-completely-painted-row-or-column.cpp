class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // cout<<m<<" "<<n<<endl;
        unordered_map<int, pair<int, int>> pos;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                pos[mat[i][j]] = {i, j};
            }
        }
        unordered_map<int, int> row_painted, col_painted;
        for(int i = 0;i < arr.size();i++){
            int num = arr[i];
            int r = pos[num].first, c = pos[num].second;
            row_painted[r]++;
            col_painted[c]++;
            if(row_painted[r] == n || col_painted[c] == m){
                return i;
            }
        }
        return -1;
    }
};