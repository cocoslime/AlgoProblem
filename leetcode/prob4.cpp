//
// Created by Dongmin on 2021/10/10.
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


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() == 0 && nums2.size() == 0) return 0.0;

    vector<int> merged;
    for (int i = 0, j = 0; i < nums1.size() || j < nums2.size();) {
        if (i == nums1.size()) {
            merged.push_back(nums2[j]);
            j++;
        } else if (j == nums2.size()) {
            merged.push_back(nums1[i]);
            i++;
        } else if (nums1[i] > nums2[j]) {
            merged.push_back(nums2[j]);
            j++;
        } else {
            merged.push_back(nums1[i]);
            i++;
        }
    }
    int half_idx = merged.size() / 2;
    if (merged.size() % 2 == 0)
        return ((double) merged[half_idx] + (double) merged[half_idx - 1]) / 2.0;
    else
        return merged[half_idx];
}

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double value = findMedianSortedArrays(nums1, nums2);
    cout << value << endl;
    return 0;
}