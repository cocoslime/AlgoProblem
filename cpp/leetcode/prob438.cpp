//
// Created by Dongmin on 2022/02/02.
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
    vector<int> answer;

    bool checkAnswer(vector<int>& curr){
        for (int i = 0 ; i < answer.size() ; i++){
            if (answer[i] != curr[i])
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        answer.assign(27, 0);
        for (auto c : p){
            answer[c - 'a'] += 1;
        }

        vector<int> current(27, 0);
        int first_idx = 0;
        for (int i = 0 ; i < s.length() ; i++){
            char c = s[i];
            current[c - 'a'] += 1;
            if (i + 1 >= p.length()){
                if (i + 1 > p.length()){
                    char remove_c = s[i - p.length()];
                    current[remove_c - 'a'] -= 1;
                }

                if (checkAnswer(current)){
                    result.push_back(first_idx);
                }

                first_idx++;
            }
        }

        return result;
    }
};

int main(){
    Solution sol;
    sol.findAnagrams("cbaebabacd",
                     "abc");
    return 0;
}