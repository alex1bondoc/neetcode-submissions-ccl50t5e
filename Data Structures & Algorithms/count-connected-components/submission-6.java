
public class Solution {
    public int countComponents(int n, int[][] edges) {
        int[] parent =  new int[n];
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        int res = n;
        for (int[] edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            while (n1 != parent[n1]) {
                parent[n1] = parent[parent[n1]];
                n1 = parent[n1];
            }
            while (n2 != parent[n2]) {
                parent[n2] = parent[parent[n2]];
                n2 = parent[n2];
            }
            if (n1 == n2) {
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
        return res;
    }
}