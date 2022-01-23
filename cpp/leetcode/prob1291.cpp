//
// Created by Dongmin on 2022/01/23.
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
    int getDigit(int number){
        int digit = 1;
        while (number / (long)pow(10, digit) != 0){
            digit++;
        }
        return digit;
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        int lowDigit = getDigit(low);
        int highDigit = getDigit(high);

//        cout << lowDigit << ","<<highDigit << endl;

        for (int i = lowDigit ; i <= highDigit ; i++){
            if (i == 10) break;

            int seqDigit = 1;
            int diff = 1;
            int j = 1;
            while (j < i){
                j++;
                diff = diff * 10 + 1;
                seqDigit = seqDigit * 10 + j;
            }

            for (int k = 0 ; k < 10 - i; k++){
                if (low <= seqDigit && seqDigit <= high)
                    result.push_back(seqDigit);
                seqDigit += diff;
            }
        }

        return result;
    }
};

int main (){
    Solution solution;
    vector<int> result = solution.sequentialDigits(10,1000000000);
    return 0;
}