class Solution {
public:
    bool solve(vector<int>& candies, long long choc, long long k){
        long long child = 0;
        for(auto& c : candies){
            child += (c / choc);
        }
        return k <= child;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, h = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while(l <= h){
            int mid = (l + h)/2;
            if(solve(candies, mid, k)){
                l = mid + 1;
                ans = mid;
            }
            else{
                h = mid - 1;
            }
        }
        // cout<<l<<" "<<h<<endl;
        return h;
    }
};