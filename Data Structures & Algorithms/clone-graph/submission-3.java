/*
Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }
        HashMap<Node, Node> oldToNew = new HashMap<>();
        Queue<Node> q = new ArrayDeque<>();
        oldToNew.put(node, new Node(node.val));
        q.add(node);
        while (q.size() > 0) {
            Node cur = q.poll();
            for (Node nei : cur.neighbors) {
                if (!oldToNew.containsKey(nei)) {
                    oldToNew.put(nei, new Node(nei.val));
                    q.add(nei);
                }
                oldToNew.get(cur).neighbors.add(oldToNew.get(nei));
            }
        }
        return oldToNew.get(node);
    }

    
}