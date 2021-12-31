//
// Created by Dongmin on 2021/10/06.
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

#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
             return s.size();

        int result = 0;
        int window_front = 0, window_back = 1;
        vector<bool> alphaExist(300, false);

        char front_c = s[window_front];
        alphaExist[front_c] = true;

        while (window_back < s.size()){
            char back_c = s[window_back];

            while (alphaExist[back_c] && window_front != window_back){
                front_c = s[window_front];
                alphaExist[front_c] = false;
                window_front++;
            }

            alphaExist[back_c] = true;
            result = max(result, window_back - window_front + 1);
            window_back++;
        }

        return result;
    }
};

int main(){
    auto s = new Solution();
    string str = " a";

    cout << s->lengthOfLongestSubstring(str) << endl;
}