//
// Created by Dongmin on 2022/02/14.
//

#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <numeric>

using namespace std;

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;

        if (root == nullptr)
            return 0;

        queue<pair<int, TreeNode*>> qu;
        qu.push(make_pair(1, root));

        while (!qu.empty()) {
            auto curr = qu.front();
            qu.pop();

            max_depth = max(max_depth, curr.first);

            if (curr.second->left != nullptr)
                qu.push(make_pair(curr.first + 1, curr.second->left));

            if (curr.second->right != nullptr)
                qu.push(make_pair(curr.first + 1, curr.second->right));
        }

        return max_depth;
    }
};