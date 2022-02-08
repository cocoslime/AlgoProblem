//
// Created by Dongmin on 2022/02/08.
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
    int addDigits(int num) {
        if (num == 0) return 0;

        int result = 0;
        string str_num = to_string(num);
        for (int i = 0 ; i < str_num.size() ; i++){
            result += str_num[i] -'0';
            while (result >= 10){
                result = result / 10 + result % 10;
            }
        }
        return result;
    }
};