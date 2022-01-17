//
// Created by Dongmin on 2022/01/17.
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

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> sList = split(s, ' ');

        if (pattern.size() != sList.size())
            return false;

        unordered_map<string, bool> alreadHas;
        unordered_map<char, string> patternMap;

        int i = 0;
        for (char c : pattern) {
            string& value = sList[i];

            if (patternMap.find(c) == patternMap.end()){
                if (alreadHas[value])
                    return false;
                patternMap[c] = value;
                alreadHas[value] = true;
            }
            else {
                if (patternMap[c] != value)
                    return false;
            }

            i++;
        }

        return true;
    }
};

int main(){

}