//
// Created by Dongmin on 2021/12/27.
//
// https://leetcode.com/problems/basic-calculator-ii/

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

int calculate(string s) {
    vector<string> expressionString;
    stringstream ss(s);

    int num;
    char ch;
    while (true) {
        ss >> num;
        expressionString.push_back(to_string(num));

        if (ss >> ch) {
            string temp;
            temp += ch;
            expressionString.push_back(temp);
        }
        else
            break;
    }

    if (expressionString.size() == 1){
        return stoi(expressionString[0]);
    }
    // multi, div
    int idx = 0;
    vector<string> expression2;

    int a = stoi(expressionString[idx]);
    while(idx != expressionString.size() - 1){
        string sign = expressionString[idx + 1];
        idx += 2;

        if (sign == "+" || sign == "-"){
            expression2.push_back(to_string(a));
            expression2.push_back(sign);
            a = stoi(expressionString[idx]);
            continue;
        }
        else {
            if (sign == "*"){
                int b = stoi(expressionString[idx]);
                a = b * a;
            }
            else{
                int b = stoi(expressionString[idx]);
                a = a / b;
            }
        }
    }

    expression2.push_back(to_string(a));
    if (expression2.size() == 1){
        return stoi(expression2[0]);
    }

    // plus, minus
    idx = 0;
    a = stoi(expression2[idx]);
    while(idx != expression2.size() - 1){
        string sign = expression2[idx + 1];
        idx += 2;

        if (sign == "+"){
            int b = stoi(expression2[idx]);
            a = a + b;
        }
        else {
            int b = stoi(expression2[idx]);
            a = a - b;
        }
    }

    return a;
}


int main(){
    cout << calculate("3+2*2");
    return 0;
}