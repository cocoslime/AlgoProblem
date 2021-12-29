//
// Created by Dongmin on 2021/12/28.
//
// https://leetcode.com/problems/number-complement/

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

int findComplement(int num) {
    vector<int> binary;

    if (num == 1) return 0;

    while (num > 1){
        int a = num / 2;
        binary.push_back(num % 2);
        num = a;
    }

    int result = 0;
    for (int i = 0; i < binary.size() ; i++){
        int a = 1 - binary[i];
        result += (int)pow(2, i) * a;
    }

    return result;
}

int main() {
    cout << findComplement(5) << endl;
    return 0;
}