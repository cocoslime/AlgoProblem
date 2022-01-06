//
// Created by Dongmin on 2022/01/06.
//
// https://leetcode.com/problems/car-pooling/
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


bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> totalPassenger(1001, 0);

    for (auto& trip : trips){
        int passenger = trip[0];
        int from = trip[1];
        int to = trip[2];

        for (int i = from ; i < to ; i++){
            totalPassenger[i] += passenger;
        }
    }

    for (int i = 0 ; i < 1001 ; i ++){
        if (totalPassenger[i] > capacity)
            return false;
    }

    return true;
}

int main(){
}