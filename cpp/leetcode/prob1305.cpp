//
// Created by Dongmin on 2022/01/26.
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
    vector<int> makeChildVector(TreeNode* root){
        vector<int> result;
        if (root == nullptr) return result;

        if (root->left){
            auto newVector = makeChildVector(root->left);
            result.insert(result.end(), newVector.begin(), newVector.end());
        }

        result.push_back(root->val);

        if (root->right){
            auto newVector = makeChildVector(root->right);
            result.insert(result.end(), newVector.begin(), newVector.end());
        }

        return result;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;

        auto newVector1 = makeChildVector(root1);
        auto newVector2 = makeChildVector(root2);

        int i = 0, j = 0;
        while (i < newVector1.size() || j < newVector2.size()){
            if (i == newVector1.size()){
                result.push_back(newVector2[j++]);
            }
            else if (j == newVector2.size()){
                result.push_back(newVector1[i++]);
            }
            else{
                if (newVector1[i] > newVector2[j]){
                    result.push_back(newVector2[j++]);
                }
                else
                    result.push_back(newVector1[i++]);
            }
        }

        return result;
    }
};