
public class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length + 1;
        int[] parent =  new int[n];
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        int res = n;
        int[] sol = new int[2];
        for (int[] edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            int sol1 = n1;
            int sol2 = n2;
            while (n1 != parent[n1]) {
                parent[n1] = parent[parent[n1]];
                n1 = parent[n1];
            }
            while (n2 != parent[n2]) {
                parent[n2] = parent[parent[n2]];
                n2 = parent[n2];
            }
            if (n1 == n2) {
                sol[0] = sol1;
                sol[1] = sol2;
                continue;
            }
            res --;
            if (rank[n1] > rank[n2]) {
                n1 = n1 + n2;
                n2 = n1 - n2;
                n1 = n1 - n2;
            }
            parent[n1] = n2;
            rank[n2] += rank[n1];
        }
        return sol;
    }
}