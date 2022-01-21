//
// Created by Dongmin on 2022/01/21.
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        bool isLast = false;
        int current = 0;

        int start = -1;
        int gasTong = 0;
        while (true) {
            gasTong += gas[current];
            gasTong -= cost[current];

            if (gasTong >= 0){
                if (start == -1)
                    start = current;
            }
            else{
                if(isLast)
                    return -1;
                start = -1;
                gasTong = 0;
            }

            current++;
            if (current == gas.size())
            {
                current =0;
                isLast = true;
            }
            if (current == start){
                return start;
            }
        }
    }
};

Solution solution;

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << solution.canCompleteCircuit(gas, cost);
    return 0;
}