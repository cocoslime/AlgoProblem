//
// Created by Dongmin on 2022/01/02.
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

int numPairsDivisibleBy60(vector<int> &time) {
    int result = 0;
    const int N = time.size();

    vector<int> countNum(60, 0);

    for (int i = 0; i < N; i++) {
        countNum[time[i] % 60]++;
    }

    for (int i = 0; i <= 30; i++) {
        int iNum = countNum[i];
        if (i == 0 | i == 30) {
            result += (iNum) * (iNum - 1) / 2;
        }
        else{
            int jNum = countNum[60 - i];
            result += iNum * jNum;
        }
    }

    return result;
}

int main() {
    vector<int> input(
            {14, 161, 302, 232, 270, 428, 155, 64, 499, 400, 25, 349, 434, 427, 5, 265, 20, 346, 463, 10, 1, 163, 189,
             345, 390, 212, 498, 281, 308, 482, 447, 217, 318, 239, 374, 449, 298, 213, 2, 230, 5, 500, 300, 390, 139,
             484, 464, 477, 111, 88, 93, 198, 181, 113, 393, 283, 383, 205, 42, 292, 335, 392, 384, 268, 361, 462, 413,
             176, 118, 111, 143, 242, 166, 286, 177, 52, 126, 342, 415, 302, 210, 48, 369, 148, 209, 87, 212, 53, 296,
             95, 97, 45, 467, 47, 373, 404, 43, 439, 19, 64, 289, 218, 268, 460, 238, 456, 490, 155, 429, 218, 301, 225,
             228, 237, 453, 267, 259, 327, 427, 169, 176, 322, 216, 451, 29, 327, 404, 177, 225, 44, 248, 174, 287, 326,
             441, 354, 110, 4, 226, 324, 331, 158, 454, 469, 354, 383, 336, 211, 133, 500, 233, 330, 471, 327, 426, 478,
             195, 232, 163, 312, 126, 51, 161, 248, 433, 348, 464, 206, 480, 478, 98, 354, 304, 424, 338, 382, 431, 379,
             194, 488, 6, 494, 394, 469, 430, 1, 207, 307, 172, 47, 269, 472, 415, 163, 309, 68, 213, 175, 343, 187, 15,
             232, 429, 389, 373, 143, 146, 88, 58, 320, 116, 82, 482, 125, 343, 329, 115, 116, 183, 389, 112, 294, 74,
             89, 62});
    cout << numPairsDivisibleBy60(input) << endl;
}