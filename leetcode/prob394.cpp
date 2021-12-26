//
// Created by Dongmin on 2021/12/26.
//

// https://leetcode.com/problems/decode-string/

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

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

bool isAlpha(char c) {
    return c >= 'a' && c <= 'z';
}

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

int readNumber(string& s, int& idx){
    string number;

    for ( ; idx < s.length() ; idx++){
        if (isNumber(s[idx]))
            number += s[idx];
        else
            break;
    }

    return stoi(number);
}

string getAnswer(string& s, int &idx){
//    cout << s[idx] << endl;
    string result = "";

    for ( ; idx < s.length() ; idx++){
        if (isAlpha(s[idx])){
            result += s[idx];
            continue;
        }
        if (s[idx] == ']')
            break;

        int k = readNumber(s, idx);
        idx++; // skip bracket

        string partAnswer = getAnswer(s, idx);

        for (int j = 0 ; j < k ; j++){
            result += partAnswer;
        }
    }

    return result;
}

string decodeString(string s) {
    string result = "";

    int i = 0;
    return getAnswer(s, i);
}

int main () {
    cout << decodeString("3[a]2[bc]") << endl;
    cout << decodeString("3[a2[c]]") << endl;
    cout << decodeString("2[abc]3[cd]ef") << endl;


    return 0;
}