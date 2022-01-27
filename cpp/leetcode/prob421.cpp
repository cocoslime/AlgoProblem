//
// Created by Dongmin on 2022/01/27.
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

class Solution {
public:
    int maxBinaryDigit = 0;

    struct TreeNode {
        int val; // no meaning
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    void insert(TreeNode* node, string& binary, int idx){
        if (binary.size() == idx) return;

        if (binary[idx] == '0'){
            if (!node->left) {
                node->left = new TreeNode(0);
            }
            insert(node->left, binary, idx + 1);
        } else {
            if (!node->right) {
                node->right = new TreeNode(0);
            }
            insert(node->right, binary, idx + 1);
        }
    }

    string findComple(TreeNode* node, string& c_binary, int idx){
        string result = "";

        char c = c_binary[idx];
        TreeNode * nextNode;

        if (node->left == nullptr){
            nextNode = node->right;
            result += '1';
        }
        else if (node->right == nullptr){
            nextNode = node->left;
            result += '0';
        }
        else{
            nextNode = c == '0' ? node->left : node->right;
            result += c;
        }

        if (idx + 1 == c_binary.size())
            return result;
        else{
            return result + findComple(nextNode, c_binary, idx + 1);
        }
    }

    string makeBinary(int num){
        string result = "";
        result += to_string(num % 2);
        num = num / 2;
        while (num != 0){
            result += to_string(num % 2);
            num = num / 2;
        }

        while (result.size() < maxBinaryDigit){
            result += '0';
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string makeCompleBinary(string& binary){
        string result = "";

        for (auto c : binary){
            result += (c == '0') ? '1' : '0';
        }

        return result;
    }

    int calcMaxDigit(int num){
        for (int i = 0 ; i <= 30 ; i++){
            if (num < (int)pow(2, i)){
                return i;
            }
        }

        return 31;
    }

    unsigned int calcXor(string a, string b){
        unsigned int result = 0;
        int j = 0;
        for (int i = a.size() - 1 ; i >= 0 ; i--){
            result += a[i] == b[i] ? 0 : (int)pow(2, j);
            j ++;
        }
        return result;
    }

    int findMaximumXOR(vector<int>& nums) {
        TreeNode* root = new TreeNode();

        sort(nums.begin(), nums.end(), greater<int>());
        maxBinaryDigit = calcMaxDigit(nums[0]);
        if (maxBinaryDigit <= 0) return 0;

        for (int num : nums){
            auto binary = makeBinary(num);
            insert(root, binary, 0);
        }

        unsigned int maxValue = 0;
        for (int num : nums){
            auto binary = makeBinary(num);
            auto c_binary = makeCompleBinary(binary);
            auto match = findComple(root, c_binary, 0);

            maxValue = max(maxValue, calcXor(binary, match));
        }

        return maxValue;
    }
};

int main(){
    vector<int> p1 = {2147483647,2147483646,2147483645};
    Solution sol;
    cout << sol.findMaximumXOR(p1);
    return 0;
}