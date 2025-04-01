class Solution {
public:
    void solve(vector<int>& count, vector<pair<int, int>>& numbers, int l, int m, int h){
        int i = l, j = m + 1;
        vector<pair<int, int>> temp;
        while(i <=m && j <= h){
            if(numbers[i].first > numbers[j].first){
                int ind = numbers[i].second;
                temp.push_back(numbers[i]);
                i++;
                count[ind] += h - j + 1;
            }
            else{
                temp.push_back(numbers[j]);
                j++;
            }
        }
        while(i<=m){
            temp.push_back(numbers[i]);
            i++;
        }
        while(j <= h){
            temp.push_back(numbers[j]);
            j++;
        }
        for(int p = 0;p < temp.size();p++){
            numbers[l + p] = temp[p];
        }
    }

    void mergeSort(vector<int>& count, vector<pair<int, int>>& numbers, int l, int h){
        if(l >= h){
            return;
        }
        int mid = l + (h - l)/2;
        mergeSort(count, numbers, l, mid);
        mergeSort(count, numbers, mid + 1, h);
        solve(count, numbers, l, mid, h);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> numbers;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            numbers.push_back({nums[i], i});
        }
        vector<int> count(n);
        mergeSort(count, numbers, 0, n - 1);
        return count;
    }
};