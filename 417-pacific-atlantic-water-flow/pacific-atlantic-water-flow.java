class Solution {
    int[] dRow = {1, -1, 0, 0};
    int[] dCol = {0, 0, 1, -1};

    static class Pair {
        int row, col;
        Pair(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int r = heights.length;
        int c = heights[0].length;
        Queue<Pair> pacificQ = new LinkedList<>();
        Queue<Pair> atlanticQ = new LinkedList<>();
        boolean[][] visPac = new boolean[r][c], visAtl = new boolean[r][c];
        for(int i = 0; i < r; i++) {
            pacificQ.offer(new Pair(i, 0));
            atlanticQ.offer(new Pair(i, c - 1));
            visPac[i][0] = true;
            visAtl[i][c - 1] = true;

        }
        for(int i = 1; i < c; i++) {
            pacificQ.offer(new Pair(0, i));
            atlanticQ.offer(new Pair(r - 1, i - 1));
            visPac[0][i] = true;
            visAtl[r - 1][i - 1] = true;
        }
        solve(pacificQ, visPac, heights);
        solve(atlanticQ, visAtl, heights);
        List<List<Integer>> ans = new ArrayList<>();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(visPac[i][j] && visAtl[i][j]) {
                    ans.add(new ArrayList<>(Arrays.asList(i, j)));
                }
            }
        }
        return ans;
    }

    private void solve(Queue<Pair> queue, boolean[][] vis, int[][] heights) {
        int r = heights.length;
        int c = heights[0].length;
        while(!queue.isEmpty()) {
            Pair cur = queue.poll();
            for(int i = 0;i < 4;i++) {
                int x = cur.row + dRow[i];
                int y = cur.col + dCol[i];
                if(inside(x, y, r, c) && !vis[x][y] && heights[x][y] >= heights[cur.row][cur.col]) {
                    queue.offer(new Pair(x, y));
                    vis[x][y] = true;
                }
            }
        }
        
    }

    private boolean inside(int x, int y, int r, int c) {
        return x >= 0 && y >= 0 && x < r && y < c;
    }
}