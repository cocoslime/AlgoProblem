//
// Created by Dongmin on 2022/01/20.
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
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1, max = 100000000;
        int best = max;

        while (min <= max){
            int mid = (min + max) / 2;
            cout << "mid : " << mid << endl;
            cout << "min : " << min << ", max : " << max << endl;

            if (time(mid, piles) <= h){
                best = mid;
                max = mid - 1;
            }
            else {
                min = mid + 1;
            }
        }

        return best;
    }

    int time(int speed, vector<int>& piles){
        int sum = 0;
        for (auto pile : piles){
            sum += ceil(1.0 * pile / speed);
        }
        return sum;
    }
};

int main(){
    vector<int> piles = {30,11,23,4,20};
    Solution* solution = new Solution();
    cout << solution->minEatingSpeed(piles, 5);
    return 0;
}