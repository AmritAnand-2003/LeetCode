class Solution {
    public int maxSum(int[] nums) {
        Set<Integer> hash = new HashSet<>();
        int sum = 0, cur = 0;
        for(int x : nums){
            if(x > 0){
                hash.add(x);
            }
        }
        if(hash.isEmpty()){
            return Arrays.stream(nums).max().getAsInt();
        }
        return hash.stream().mapToInt(Integer::intValue).sum();
    }
}