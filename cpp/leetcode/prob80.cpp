//
// Created by Dongmin on 2022/02/06.
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
    const int END = 100001;

    int removeDuplicates(vector<int>& nums) {
        int result = nums.size();

        int i = 0;
        while (i < nums.size() && nums[i] <= 10000) {
            int start_i = i;
            int start = nums[i];

            i++;
            while (i < nums.size() && nums[i] == start){
                i++;
            }

            int dup_nums = i - start_i;
            if (dup_nums > 2){
                result -= dup_nums - 2;
                nums.erase(nums.begin() + start_i, nums.begin() + start_i + dup_nums - 2);
                for (int j = 0 ; j < dup_nums - 2 ; j++)
                    nums.push_back(END);
                i = start_i + 2;
            }
        }

        return result;
    }
};


int main() {
    Solution sol;

    vector<int> nums = {1,1,1,2,2,2,3,3};
    cout << sol.removeDuplicates(nums) << endl;
    for (auto i : nums)
        cout << i << ",";
}