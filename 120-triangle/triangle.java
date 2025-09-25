class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int rows = triangle.size();
        for(int i = rows - 2; i >= 0; i--) {
            for(int j = 0;j < triangle.get(i).size(); j++) {
                int cur_val = triangle.get(i).get(j);
                triangle.get(i).set(j, cur_val + Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1)));
            }
        }
        return triangle.get(0).get(0);
    }
}