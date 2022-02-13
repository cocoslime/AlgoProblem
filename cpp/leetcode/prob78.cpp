//
// Created by Dongmin on 2022/02/13.
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.emplace_back();

        int i = 0;
        while (i < nums.size()){
            int n = result.size();
            for (int j = 0 ; j < n ; j++){
                vector<int> new_list(result[j]);
                new_list.push_back(nums[i]);
                result.push_back(new_list);
            }

            i++;
        }

        return result;

    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution solution;
    solution.subsets(nums);

    return 0;
}