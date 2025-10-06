class Solution {
    static class Cell implements Comparable<Cell> {
        int height;
        int row;
        int col;
        Cell(int height, int row, int col) {
            this.height = height;
            this.row = row;
            this.col = col;
        }
        @Override
        public int compareTo(Cell other) {
            return Integer.compare(this.height, other.height);
        }
    }

    public int swimInWater(int[][] grid) {
        PriorityQueue<Cell> q = new PriorityQueue<>();
        int[] rDir = {1, -1, 0, 0};
        int[] cDir = {0, 0, 1, -1};
        int r = grid.length, c = grid[0].length;
        boolean[][] vis = new boolean[r][c];
        vis[0][0] = true;
        q.offer(new Cell(grid[0][0], 0, 0));
        while(!q.isEmpty()) {
            Cell cur = q.poll();
            if(cur.row == r - 1 && cur.col == c - 1){
                return cur.height;
            }
            for(int i = 0;i < 4; i++) {
                int x = cur.row + rDir[i], y = cur.col + cDir[i];
                if(inside(x, y, r, c) && vis[x][y] == false) {
                    vis[x][y] = true;
                    q.offer(new Cell(Math.max(cur.height, grid[x][y]), x, y));
                }
            }
        }
        return -1;
    }

    private boolean inside(int i, int j, int r, int c) {
        return i >= 0 && j >= 0 && i < r && j < c;
    }
}