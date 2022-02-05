//
// Created by Dongmin on 2022/02/05.
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

// https://leetcode.com/problems/contiguous-array/discuss/1743637/C%2B%2B-with-Explanation-oror-Easy-to-Understand-oror-Unordered_Map

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sum_map;
        sum_map[0] = -1;
        int n = nums.size();
        int sum = 0;
        int longest = 0;
        for (int i = 0 ; i < n; i++){
            sum += nums[i] == 0 ? -1 : 1;
            if (sum_map.find(sum) != sum_map.end()){
                longest = max(longest, i - sum_map[sum]);
            }
            else
                sum_map[sum] = i;
        }

        return longest;
    }
};

int main(){
    Solution sol;
    vector<int> nums;
    ifstream infile( "../input.txt" );

    while (infile)
    {
        string line;
        if (!getline( infile, line )) break;

        string s;
        istringstream ss( line );

        while (getline(ss, s, ',' )) {
            nums.push_back(atoi(s.c_str()));
        }
    }

    if (!infile.eof())
    {
        cerr << "Fooey!\n";
    }

    cout << "nums : " << nums.size() << endl;
    cout << sol.findMaxLength(nums);
    return 0;
}