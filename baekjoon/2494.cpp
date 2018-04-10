//
// Created by Dong's MacBook Pro on 2018. 4. 9..
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define INF 1000000000
#define MAXN 10001
int N, global_result;
int target[MAXN];
int current_array[MAXN];
int dp[MAXN][10];
int turn_track[MAXN];

void track_result(int i, int result);

void print_track();

int func(int index, int pTurn){
    if (index == N) return 0;
    int current = current_array[index] + pTurn;
    current = current >= 10 ? current - 10 : current;
    int &result = dp[index][current];
    if (result != -1) return result;

    int left_turn = target[index] - current;
    int right_turn;
    if (left_turn >= 0){
        right_turn = 10 - left_turn;
    }
    else{
        right_turn = abs(left_turn);
        left_turn = 10 + left_turn;
    }

    int next_left_turn = pTurn + left_turn >= 10 ? pTurn + left_turn - 10 : pTurn + left_turn;

    int left_result = left_turn + func(index + 1, next_left_turn);
    int right_result = right_turn + func(index+1, pTurn);
    result = min (left_result, right_result);

    return result;
}

int main(){
    memset(dp,-1, sizeof(dp));
    cin >> N;

    for (int i = 0 ; i < N ; i++){
        char c;
        cin >> c;
        current_array[i] = c - '0';
    }
    for (int i = 0 ; i < N ; i++){
        char c;
        cin >> c;
        target[i] = c - '0';
    }

    global_result = func(0, 0);
    track_result(0, 0);
    print_track();
    return 0;
}

void print_track() {
    printf("%d\n", global_result);
    for (int i = 0 ; i < N ; i++){
        printf("%d %d\n", i+1, turn_track[i]);
    }
}

void track_result(int index, int pTurn) {
    if (index == N) return;
    int current = current_array[index] + pTurn >= 10 ? current_array[index] + pTurn - 10 : current_array[index] + pTurn;
    int left_turn = target[index] - current;
    int right_turn;
    if (left_turn >= 0){
        right_turn = 10 - left_turn;
    }
    else{
        right_turn = abs(left_turn);
        left_turn = 10 + left_turn;
    }

    int next_left_turn = pTurn + left_turn >= 10 ? pTurn + left_turn - 10 : pTurn + left_turn;

    int left_result = left_turn + func(index + 1, next_left_turn);
    int right_result = right_turn + func(index+1, pTurn);

    if (left_result < right_result){
        turn_track[index] = left_turn;
        return track_result(index + 1, next_left_turn);
    }
    else{
        turn_track[index] = -right_turn;
        return track_result(index+1, pTurn);
    }
}