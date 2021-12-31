//
// Created by Dongmin on 2021/10/10.
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

int rangeBitwiseAnd(int left, int right) {
    if (left == right) return left;

    int count = 0;
    while (left != right){
        left = left >> 1;
        right = right >> 1;
        count++;
    }
    if (left == 0)
        return 0;
    return (left << count);
}

int main(){
    cout << rangeBitwiseAnd(1, 0) << endl;
    cout << rangeBitwiseAnd(6, 7) << endl; // 6
    return 0;
}