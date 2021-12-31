//
// Created by Dong's MacBook Pro on 2018. 5. 17..
//

#include <iostream>
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
#include <cassert>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

#define INF 10000000

int K;
int big_digit[101]; //남은 성냥개비로 만들 수 있는 최대 자리수.
int big_number[101];
int small_digit[101];
int small_number[101];

int matches_num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void print_max(int k, bool b);

void print_min(int k, bool b);

int func_min(int num, bool isFirst = false){
    if (num == 0) return 0;
    if (num < 2) return INF;
    int& min_digit = small_digit[num];
    if (min_digit != -1) return min_digit;

    min_digit = INF;
    for (int i = 0 ; i < 10 ; i++){
        if (isFirst && i == 0) continue;
        int next = 1 + func_min(num - matches_num[i]);
        if (next < min_digit){
            small_number[num] = i;
            min_digit = next;
        }
    }
    return min_digit;
}

int func_max(int num, bool isFirst = false){
    if (num == 0) return 0;
    if (num < 2) return -100000000;
    int& max_digit = big_digit[num];
    if (max_digit != -1) return max_digit;
    max_digit = 0;
    for (int i = 0 ; i < 10 ; i++){
        if (isFirst && i == 0) continue;
        int next = 1 + func_max(num - matches_num[i]);
        if (next >= max_digit){
            big_number[num] = i;
            max_digit = next;
        }
    }
    return max_digit;
}

int main(){
    int test_case; cin >> test_case;

    while (test_case-- ){
        std::fill(big_digit, big_digit + 101, -1);
        std::fill(small_number, small_number + 101, -1);
        std::fill(big_number, big_number + 101, -1);
        std::fill(small_digit, small_digit + 101, -1);
        cin >> K;
        func_max(K, true);
        func_min(K, true);

        print_min(K, true);
        printf(" ");
        print_max(K, true);
        printf("\n");
    }

    return 0;
}

void print_min(int k, bool b = false) {
    if (k == 0) return;
    assert (k > 0);
    int num = small_number[k];
    assert(!(b && num == 0 ));
    printf("%d", num);
    print_min(k - matches_num[num]);
}

void print_max(int k, bool b = false) {
    if (k == 0) return;
    assert (k > 0);
    int num = big_number[k];
    assert(!(b && num == 0 ));
    printf("%d", num);
    print_max(k - matches_num[num]);
}