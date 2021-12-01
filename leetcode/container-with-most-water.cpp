//
// Created by Dongmin on 2021/12/01.
//
//https://leetcode.com/problems/container-with-most-water/

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

#define MAX_HEIGTH 10000

int maxArea(vector<int>& height) {
    vii heightMinMax(MAX_HEIGTH + 1, ii(height.size(), -1));

    for (int idx = 0 ; idx < height.size(); idx++){
        int heightValue = height[idx];
        heightMinMax[heightValue].first = min(heightMinMax[heightValue].first, idx);
        heightMinMax[heightValue].second = max(heightMinMax[heightValue].second, idx);
    }

    int result = 0;
    int preMin = INT_MAX;
    int preMax = 0;
    for (int currHeight = MAX_HEIGTH; currHeight>0 ; currHeight--){
        if (heightMinMax[currHeight].second == -1) continue;

        preMin = min(preMin, heightMinMax[currHeight].first);
        preMax = max(preMax, heightMinMax[currHeight].second);
        result = max(result, (preMax - preMin) * currHeight);
    }

    return result;
}


int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    vector<int> height2 = {1, 2};
    cout << maxArea(height2) << endl;

    vector<int> height3 = {1, 2, 1};
    cout << maxArea(height3) << endl;
    return 0;
}