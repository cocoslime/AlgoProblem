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

/*
 *
언어는 cpp, java, python, - 중 하나입니다.
직군은 backend, frontend, - 중 하나입니다.
경력은 junior, senior, - 중 하나입니다.
소울푸드는 chicken, pizza, - 중 하나입니다.
 */
int toCode(string str)
{
    if (str == "cpp" || str == "backend" || str == "junior" || str == "chicken")
        return 1;
    if (str == "java" || str == "frontend" || str == "senior" || str == "pizza")
        return 2;
    if (str == "python") return 3;
    return 0;
}

unordered_map<int, multiset<int>> score_map;

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
            int key = 0;
            for (int j = 0; j < 4 ; j++)
            {
                if (one_mask[j]){
                    key += toCode(splited[j]) * (int)pow(10, j);
                }
            }
            key += 10000;
            score_map[key].insert(score);
        }
    }

    for (auto& qr : query){
        vector<int> qr_int;
        int key =0 ;

        vector<string> splited = split(qr, ' ');

        splited.erase(std::remove_if(splited.begin(), splited.end(),
                                     [](string x) { return x == "and"; }),
                      splited.end());
#if 0

      //  string key;
        for (int i = 0 ; i < 4; i++)
            key += splited[i];
#else
        for (int i = 0 ; i < splited.size() - 1; i++) {
            key += toCode(splited[i]) * (int)pow(10, i);
        }
        key += 10000;
#endif
//        cout << " key : " << key << endl;
        int score_cond;
        score_cond = strToInt(splited.back());

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