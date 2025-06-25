class Solution {
public:
    int helper(vector<int>& nums2, long long x1, long long tar){
        int n2 = nums2.size();
        int left = 0, right = n2 - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if((x1 >= 0 && nums2[mid] * x1 <= tar) || (x1 < 0 && nums2[mid] * x1 > tar)){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if( x1 >= 0){
            return left;
        }
        else{
            return n2 - left;
        }
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while(left <= right){
            long long mid = (left + right)/2;
            long long count = 0;
            for(auto& val : nums1){
                count += helper(nums2, val, mid);
            }
            if(count >= k){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};