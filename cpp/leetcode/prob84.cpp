//
// Created by Dongmin on 2022/01/29.
//
// https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/1727605/C%2B%2B-Simple-Solution-or-Brute-Force-Optimal-or-W-Explanation
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left_bounds(n, 0);
        vector<int> right_bounds(n, n);

        stack<int> st;
        for (int i = 0 ; i < n ; i++){
            while (!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if (st.empty()) left_bounds[i] = 0;
            else left_bounds[i] = st.top() + 1;

            st.push(i);
        }

        while (!st.empty()) st.pop();







        int maxHeight = -1;
        for (int height : heights){
            maxHeight = max(maxHeight, height);
        }

        int maxArea = 0;
        for (int height = 1 ; height <= maxHeight ; height++){
            int maxLength = 0;
            int currLength = 0;
            for (int i = 0 ; i < heights.size() ; i++){
                if (heights[i] >= height){
                    currLength++;
                }
                else{
                    maxLength = max(maxLength, currLength);
                    currLength = 0;
                }
            }
            maxLength = max(maxLength, currLength);

            maxArea = max(maxArea, maxLength * height);
        }

        return maxArea;
    }
};

int main(){
    Solution solution;
    vector<int> heights = {2,1,5,6,2,3};
    cout << solution.largestRectangleArea(heights);
    return 0;
}