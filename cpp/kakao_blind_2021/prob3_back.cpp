//
// Created by dongmin on 2021/09/05.
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

using namespace std;

int strToInt(string str) {
    std::stringstream ss(str);
    int n;
    ss >> n;
    return n;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

unordered_map<string, multiset<int>> score_map;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (auto& a : info)
    {
        // "java backend junior pizza 150"
        vector<string> splited = split(a, ' ');
        int score = strToInt(splited.back());

        vector<vector<bool>> mask;
        vector<bool> tf = {false, true};
        for (bool i : tf)        {
            for (bool j : tf)            {
                for (bool k : tf)            {
                    for (bool w : tf)            {
                        mask.push_back({i,j,k,w});
                    }
                }
            }
        }

        for (int i = 0 ; i < mask.size(); i++){
            auto& one_mask = mask[i];
            string key = "";
            for (int j = 0; j < 4 ; j++)
            {
                if (one_mask[j]){
                    key += splited[j];
                }
                else{
                    key += "-";
                }
            }
            score_map[key].insert(score);
        }
    }

    for (auto& qr : query){
        vector<int> qr_int;

        vector<string> splited = split(qr, ' ');

        string key;
        for (int i = 0 ; i < splited.size() - 1; i++) {
            if (splited[i] == "and")
                continue;
            key += splited[i];
        }

        cout << key << endl;
        int score_cond;
        score_cond = strToInt(splited[4]);

        auto ptr = score_map[key].lower_bound(score_cond);
        auto count = distance(ptr, score_map[key].end());
        answer.push_back(count);
    }

    return answer;
}

int main()
{
    vector<string> infos = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> queries = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    vector<int> result = solution(infos, queries);
    for(auto& a : result){
        cout << a << endl;
    }
    return 0;
}