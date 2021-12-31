//
// Created by Dongmin on 2021/12/29.
//
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (root == NULL) return NULL;

    queue<Node*> st;
    st.push(root);

    do {
        queue<Node *> next_st;
        Node *next = NULL;

        while (!st.empty()) {
            Node *fr = st.front();
            st.pop();

            fr->next = next;
            next = fr;

            if (fr->right != NULL) {
                next_st.push(fr->right);
                next_st.push(fr->left);
            }
        }

        if (next_st.empty()) break;

        while (!next_st.empty()) {
            st.push(next_st.front());
            next_st.pop();
        }

    } while (true);

    return root;
}

int main(){
    return 0;
}