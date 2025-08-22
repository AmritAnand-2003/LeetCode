class Solution {
    public int component_count(List<List<int []>> graph, int time, int n) {
        boolean[] visited = new boolean[n];
        int count = 0;
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                count++;
                dfs(i, graph, visited, time);
            }
        }
        return count;
    }

    public void dfs(int node, List<List<int []>> graph, boolean[] visited, int time){
        visited[node] = true;
        for(int[] ngbr : graph.get(node)) {
            if(!visited[ngbr[0]] && ngbr[1] > time){
                dfs(ngbr[0], graph, visited, time);
            }
        }
    }

    public int minTime(int n, int[][] edges, int k) {
        int l_time = 0, h_time = (int)1e9;
        List<List<int[]>> graph = new ArrayList<>();
        for(int i = 0; i < n; i++){
            graph.add(new ArrayList<>());
        }
        for(int[] e : edges){
            int u = e[0], v = e[1], w = e[2];
            graph.get(u).add(new int[]{v, w});
            graph.get(v).add(new int[]{u, w});
        }
        int ans = -1;
        while(l_time <= h_time){
            int mid = (l_time + h_time) / 2;
            int comp_count = component_count(graph, mid, n);
            if(comp_count >= k){
                ans = mid;
                h_time = mid - 1;
            }
            else{
                l_time = mid + 1;
            }
        }
        return ans;
    }
}