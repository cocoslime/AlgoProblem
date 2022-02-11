//
// Created by Dongmin on 2022/02/11.
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
    bool isMatch(vector<int>& a, vector<int>& b){
        for (int i = 0 ; i < a.size() ; i++){
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> current(27, 0);
        vector<int> answer (27, 0);

        // make answer
        for (auto c : s1){
            answer[c - 'a']++;
        }

        for (int i = 0 ; i < s2.length() ; i++){
            current[s2[i] - 'a']++;
            if (i >= s1.length()) {
                char c = s2[i - s1.length()];
                current[c - 'a']--;
            }

            if (isMatch(answer, current))
                return true;
        }

        return false;
    }
};

