//
// Created by Dongmin on 2022/01/14.
//
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
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

typedef vector<int> Point;
bool comp(vector<int>& a, vector<int>& b){
    if (a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}


class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), comp);

        int shoot = 0;
        for (int i = 0 ; i < points.size() ; i++) {
            shoot++;
            Point& point = points[i];

            int end = point[1];
            for (int j = i + 1; j < points.size() ; j++){
                if (points[j][0] <= end){
                    i++;
                    end = min(end, points[j][1]);
                }
                else
                    break;
            }
        }

        return shoot;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout << solution.findMinArrowShots(points) << endl;
    vector<vector<int>> points2 = {{1,2},{2,3},{3,4},{4,5}};
    cout << solution.findMinArrowShots(points2) << endl;
    return 0;
}