class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int area = 0;
        int diagSq = 0;
        for(int i = 0;i < dimensions.length; i++){
            int length = dimensions[i][0], breadth = dimensions[i][1];
            int cur_diag = length * length + breadth * breadth;
            if(cur_diag > diagSq) {
                area = length * breadth;
                diagSq = cur_diag;
            }
            else if(cur_diag == diagSq) {
                area = Math.max(area, length * breadth);
            }
        }
        return area;
    }
}