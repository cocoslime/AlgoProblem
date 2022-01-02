//
// Created by Dongmin on 2022/01/01.
//
//https://leetcode.com/problems/burst-balloons/
// help : https://leetcode.com/problems/burst-balloons/discuss/1659268/C%2B%2B-EASY-TO-UNDERSTAND-oror-All-Intuitions-step-by-step-with-detailed-explanations
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

vector<vector<int>> cache;
vector<int> new_nums;

int dp(int start, int end){
    if (start + 1 == end) return 0;

    int& value = cache[start][end];
    if (value != -1)
        return value;

    value = 0;
    for (int k = start + 1 ; k < end ; k++){
        value = max(value, dp(start, k) + dp(k, end) + new_nums[start] * new_nums[k] * new_nums[end]);
    }
    return value;
}

int maxCoins(vector<int>& nums) {
    int n = nums.size() + 2;
    cache.assign(n, vector<int>(n, -1));
    new_nums.assign(n,1);
    for (int i = 0 ; i < nums.size() ; i++){
        new_nums[i+1] = nums[i];
    }

    return dp(0, n - 1);
}

int main(){
//    vector<int> param1 = {9,76,64,21,97,60};
    vector<int> param1 = {8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2};
//    vector<int> param1 = {3,1,5,8};

    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    cout << maxCoins(param1) <<endl;
    std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
    cout << "Seconds : " << sec.count() << "s" << endl;
    return 0;
}
