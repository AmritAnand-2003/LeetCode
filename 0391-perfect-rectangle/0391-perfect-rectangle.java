class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;
        long totalArea = 0;
        Map<String, Integer> pointFreq = new HashMap<>();
        for(int[] rect : rectangles){
            int x1 = rect[0], y1 = rect[1];
            int x2 = rect[2], y2 = rect[3];
            minX = Math.min(minX, x1);
            minY = Math.min(minY, y1);
            maxX = Math.max(maxX, x2);
            maxY = Math.max(maxY, y2);
            totalArea += (long)(x2 - x1) *(y2 - y1);
            String[] points = {
                x1 + " " + y1,
                x1 + " " + y2,
                x2 + " " + y1,
                x2 + " " + y2
            };
            for(String point : points){
                pointFreq.put(point, pointFreq.getOrDefault(point, 0) + 1);
            }
        }
        Iterator<Map.Entry<String, Integer>> iterator = pointFreq.entrySet().iterator();
        while (iterator.hasNext()) {
            Map.Entry<String, Integer> entry = iterator.next();
            if (entry.getValue() % 2 == 0) {
                iterator.remove();
            }
        }
        if(pointFreq.size() != 4 || !pointFreq.containsKey(minX + " " + minY) || !pointFreq.containsKey(minX + " " + maxY) || !pointFreq.containsKey(maxX + " " + minY) || !pointFreq.containsKey(maxX + " " + maxY)){
            return false;
        }
        long boundingArea = (long) (maxX - minX) * (maxY - minY);
        if(totalArea != boundingArea){
            return false;
        }
        return true;
    }
}