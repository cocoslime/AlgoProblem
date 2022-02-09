//
// Created by Dongmin on 2022/02/09.
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
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        sort(nums.begin(), nums.end());

        int before = INT_MAX;
        for (int i = 0 ; i < nums.size() - 1; i++){
            int n = nums[i];
            if (n == before) continue;
            before = n;

            auto ptr = lower_bound(nums.begin() + i + 1, nums.end(), n + k);
            if (*ptr == n + k){
                result += 1;
            }
        }
        return result;
    }
};

