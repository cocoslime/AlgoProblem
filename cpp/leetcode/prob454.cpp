//
// Created by Dongmin on 2022/02/03.
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map1;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            int num1 = nums1[i];
            for (int j = 0 ; j < n; j++){
                int num2 = nums2[j];
                int num = num1 + num2;
                if (map1.find(num) != map1.end()){
                    map1[num]++;
                }
                else
                    map1[num] = 1;
            }
        }

        unordered_map<int, int> map2;
        for( const auto& numPair : map1 ) {
            for (int i = 0; i < n; i++) {
                int num = numPair.first + nums3[i];
                if (map2.find(num) != map2.end()){
                    map2[num] += numPair.second;
                }
                else
                    map2[num] = numPair.second;
            }
        }

        int result = 0;
        for( const auto& numPair : map2 ) {
            for (int i = 0; i < n; i++) {
                int num = numPair.first + nums4[i];
                if (num == 0) result += numPair.second;
            }
        }

        return result;
    }
};