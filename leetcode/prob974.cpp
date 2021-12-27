//
// Created by Dongmin on 2021/12/27.
//
//https://leetcode.com/problems/k-closest-points-to-origin/


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

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

bool compare(vector<int>& a, vector<int>& b) {
    return ( a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    sort(points.begin(), points.end(), compare);
    vector<vector<int>> result(points.begin(), points.begin() + k);
    return result;
}