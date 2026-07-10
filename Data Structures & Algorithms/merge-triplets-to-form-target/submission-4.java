class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        int x = 0, y = 0, z = 0;
        for (int[] trip : triplets) {
            if (trip[0] > target[0] || trip[1] > target[1] || trip[2] > target[0]){
                continue;
            }
            System.out.println("ok");
            if (trip[0] == target[0])
                x = 1;
            if (trip[1] == target[1])
                y = 1;
            if (trip[2] == target[2])
                z = 1;
        }
        System.out.println(x + " " + y + " " + z);
        return x == 1 && y == 1 && z == 1;
    }
}
