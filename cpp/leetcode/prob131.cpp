//
// Created by Dongmin on 2022/01/05.
//
// https://leetcode.com/problems/palindrome-partitioning/
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

bool isPalindrome(string str){
    if (str.size() == 1) return true;
    int j = str.size() - 1;
    for (int i = 0 ; i < str.size() / 2 + 1 ; i ++){
        if (str[i] != str[j])
            return false;
        j--;
    }
    return true;
}
vector<vector<string>> recursive(vector<string> preAnswer, string s){
    vector<vector<string>> result;

    if (s.size() == 1) {
        preAnswer.push_back(s);
        result.push_back(preAnswer);
        return result;
    }

    int size = s.size();
    for (int i = 1 ; i <= s.size() ; i++ ){
        string part1 = s.substr(0, i);
        if (isPalindrome(part1)) {
            vector<string> newPreAnswer(preAnswer);
            newPreAnswer.push_back(part1);

            if (i == s.size()) {
                result.push_back(newPreAnswer);
            }
            else{
                vector<vector<string>> partAnswer = recursive(newPreAnswer, s.substr(i, size));
                for (vector<string>& a : partAnswer){
                    result.push_back(a);
                }
            }
        }
    }

    return result;
}

vector<vector<string>> partition(string s) {
    return recursive({}, s);
}

int main(){
    cout << isPalindrome("aba") << endl;
    auto answer = partition("aba");
    for (auto& a : answer){
        for (auto& b : a) {
            cout << b << ",";
        }
        cout << endl;
    }
    return 0;
}