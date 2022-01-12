//
// Created by Dongmin on 2022/01/12.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void insert(TreeNode* node, int val){
        if (node->val < val) {
            if (node->right == nullptr)
                node->right = new TreeNode(val);
            else
                insert(node->right, val);
        }
        else
        {
            if (node->left == nullptr)
                node->left = new TreeNode(val);
            else
                insert(node->left, val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            root = new TreeNode(val);
        else
            insert(root, val);

        return root;
    }
};