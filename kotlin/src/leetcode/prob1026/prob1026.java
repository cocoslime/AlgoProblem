package leetcode.prob1026;

/**
 * Definition for a binary tree node.
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private int maxDiff = 0;

    private void dfs(TreeNode node, int currMax, int currMin) {
        int diffWithMax = Math.abs(node.val - currMax);
        int diffWithMin = Math.abs(node.val - currMin);

        maxDiff = Math.max(maxDiff, diffWithMax);
        maxDiff = Math.max(maxDiff, diffWithMin);

        currMax = Math.max(currMax, node.val);
        currMin = Math.min(currMin, node.val);

        if (node.right != null)
            dfs(node.right, currMax, currMin);
        if (node.left != null)
            dfs(node.left, currMax, currMin);
    }

    public int maxAncestorDiff(TreeNode root) {
        maxDiff = 0;

        dfs(root, root.val, root.val);

        return maxDiff;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1, null, new TreeNode(2, null, new TreeNode(0, new TreeNode(3, null, null), null)));
        int result = new Solution().maxAncestorDiff(root);
        System.out.println(result);
    }
}
