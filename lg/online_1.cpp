
#define _CRT_SECURE_NO_WARNINGS

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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ii;
typedef vector<int> vi;
typedef vector<ii> vii;


#define INF 1000000000

#include <iostream>
#include <fstream>

ofstream fout("/Users/dong/Documents/dev/workspace/AlgoProblem/lg/res.txt");
ifstream fin("input.txt");
FILE* fp;

int N;
vector<ll> order;
vector<ll_ii> equation;

bool compareorder(ll& a, ll& b){
    if (equation[a].second > equation[b].second)
        return true;
    else if (equation[a].second < equation[b].second){
        return false;
    }
    else
    {
        if (equation[a].first > equation[b].first)
            return true;
        else if (equation[a].first < equation[b].first){
            return false;
        }
        else
            return a > b;
    }
}

ll calcMIN(){
    ll min_value = 0;
    for (ll i = 0 ; i < N ; i++){
        ll multiple = (i+1) * (order[i] + 1);
        ll new_min_value = min_value + multiple;
        if (new_min_value < min_value){
            cout << "exceed" << endl;
        }
        min_value = new_min_value;
    }
    return min_value;
}

ll calcMAX(){
    ll max_value = equation[order[0]].second;
    for (int i = 1 ; i < N ; i++){
        ll index = order[i];
        max_value = max_value * 2;
        max_value += equation[index].second;
    }
    return max_value;
}

ll calcMAX(vector<ll>& order){
    ll max_value = equation[order[0]].second;
    for (int i = 1 ; i < order.size() ; i++){
        ll index = order[i];
        max_value = max_value * equation[index].first;
        max_value += equation[index].second;
    }
    return max_value;
}

ll findMinimum(){
    ll min_value = LONG_MAX;
    ll max_value = LONG_MIN;


    /** DATA 3 */
//    vector<ll> temp_order;
//    for (ll i = 0 ; i < N ; i++){
//        ll temp_max = LONG_MIN;
//        ll index = 0;
//        for (ll j = 0 ; j < temp_order.size() + 1 ; j++){
//            temp_order.insert(temp_order.begin() + j, i);
//            ll temp = calcMAX(temp_order);
//            temp_order.erase(temp_order.begin() + j);
//            if (temp > temp_max){
//                index = j;
//                temp_max = temp;
//            }
//        }
//        temp_order.insert(temp_order.begin() + index, i);
//    }
    
/** DATA 2 */
//    if (equation[0].first > 0 )
//        sort(order.begin(), order.begin() + N, compareorder);
//    min_value = calcMIN();

    
/** DATA 1 */
//    int per = 0;
//    do {
//        per ++;
//        if (per % 5000 == 0) cout << per << " / " << N << endl;
//        ll temp = calcMAX();
//        if (temp > max_value){
//            max_value = temp;
//            min_value = calcMIN();
//        }
//        else if(temp == max_value){
//            ll min_temp = calcMIN();
//            if (min_temp < min_value){
//                min_value = min_temp;
//            }
//        }
//    } while ( std::next_permutation(order.begin(),order.begin()+N) );
    cout << "a : " << equation[order[0]].first <<endl;
    for (int i = 0 ; i < 50 ; i++){
        //cout << equation[order[i]].second << endl;
    }
    return min_value;
}

int main() {
    fp = fopen("/Users/dong/Documents/dev/workspace/AlgoProblem/lg/input.txt", "r");//stdin;
    int test_case;
    fscanf(fp, "%d", &test_case);
    int test_num = 0;
    while (test_case--) {
        test_num++;
        //if (test_num == 1) continue;
        fscanf(fp, "%d", &N);
        equation.clear();
        order.clear();
        for (ll i = 0; i < N ; i++){
            ll a, b;
            fscanf(fp, "%lld %lld", &a, &b);
            equation.push_back(ll_ii(a,b));
            order.push_back(i);
        }
        ll min_value = findMinimum();
        cout << min_value << endl;
        fout << min_value << endl;
        equation.clear();
    }
    
    fout.close();
    return 0;
    
}

