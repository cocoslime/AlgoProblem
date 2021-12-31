//
// Created by dongmin on 2021/09/04.
//

#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
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

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<int> order_count(30, 0);
    vector<int> menu;
    vector<unsigned int> orders_bit(30, 0);

    for (int i = 0 ; i < orders.size() ; i++)
    {
        auto& str = orders[i];
        sort(orders.begin(), orders.end());
        for (char &c : str)
        {
            order_count[c - 'A']++;
            orders_bit[i] |= 1 << (int)(c-'A');
        }
    }

    for (int i = 0 ; i < 30 ; i++)
    {
        if (order_count[i] >= 1)
            menu.push_back(i);
    }

    vector<int> comb(30, 0);

    for (auto& course_num : course){
        vector<string> temp_answer;
        int max_count = 0;

        if (menu.size() < course_num)
            break;

        int k = course_num;
        vector<int> ind(k, 1);

        for(int i=0; i< menu.size() - k; i++){
            ind.push_back(0);
        }

        sort(ind.begin(), ind.end());
        do{
            comb.clear();
            // 출력
            for(int i=0; i<ind.size(); i++){
                if(ind[i] == 1){
                    comb.push_back(menu[i]);
                }
            }

            unsigned int compare_course = 0;
            for (auto& a : comb){
                compare_course |= 1 << a;
            }

            int count = 0;
            for (int i = 0 ; i < orders_bit.size() ; i++)
            {
                if ((orders_bit[i] & compare_course) == compare_course){
                    count++;
                }
            }

            if (count >= 2 && count >= max_count) {
                if (count > max_count) {
                    max_count = count;
                    temp_answer.clear();
                }
                string ans;
                for (int i = 0; i < k; i++) {
                    ans.push_back((char) ('A' + comb[i]));
                }
                temp_answer.push_back(ans);
            }

        }while(next_permutation(ind.begin(), ind.end()));

        answer.insert(answer.end(), temp_answer.begin(), temp_answer.end());
    }
    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2,3,4};

    vector<string> result = solution(orders, course);

    cout << "==============" <<endl;
    for (auto& res : result)
        cout << res << endl;
    return 0;
}