//
// Created by stem_dong on 2018-08-06.
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
#define MAX_N 101

int dir[6][3] = {
        {0,0,1},
        {0,0,-1},
        {1,0,0},
        {-1,0,0},
        {0,1,0},
        {0,-1,0}
};
int min_day[MAX_N][MAX_N][MAX_N];
int tomato[MAX_N][MAX_N][MAX_N];

int N, M, H;

void bfs(){
    bool checked[MAX_N * MAX_N * MAX_N] = {0};

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i = 0 ; i < H ; i++){
        for (int j = 0 ; j < N ; j++){
            for (int k = 0 ; k < M ; k ++){
                if(tomato[i][j][k] == 1){
                    pq.emplace(0, i * MAX_N * MAX_N + j * MAX_N + k);
                }
            }
        }
    }

    while (!pq.empty()){
        int cost = pq.top().first;
        int flat_locate = pq.top().second;
        pq.pop();
        if (checked[flat_locate]) continue;

        checked[flat_locate] = true;
        int curr_h = flat_locate / (MAX_N * MAX_N);
        int curr_n = (flat_locate % (MAX_N * MAX_N)) / MAX_N;
        int curr_m = flat_locate % MAX_N;

        min_day[curr_h][curr_n][curr_m] = cost;

        for (auto &i : dir) {
            int next_h = curr_h + i[0];
            int next_n = curr_n + i[1];
            int next_m = curr_m + i[2];

            if (next_h < 0 || next_h >= H || next_n < 0 || next_n >= N || next_m < 0 || next_m >= M){ // out of bound
                continue;
            }
            if(tomato[next_h][next_n][next_m] == 0){
                if (min_day[next_h][next_n][next_m] > cost + 1)
                    pq.emplace(cost + 1, next_h * MAX_N * MAX_N + next_n * MAX_N + next_m );
            }
        }
    }
}

int main(){
    cin >> M >> N >> H;
    for (int i = 0 ; i < H ; i++){
        for (int j = 0 ; j < N ; j++){
            for (int k = 0 ; k < M ; k ++){
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] != -1)
                    min_day[i][j][k] = INF;
                else
                    min_day[i][j][k] = 0;
            }
        }
    }

    bfs();
    int max_day = -1;
    for (int i = 0 ; i < H ; i++){
        for (int j = 0 ; j < N ; j++){
            for (int k = 0 ; k < M ; k ++){
                if (min_day[i][j][k] == INF){
                    printf("-1\n");
                    return 0;
                }
                if (min_day[i][j][k] > max_day){
                    max_day =min_day[i][j][k];
                }
            }
        }
    }

    printf("%d\n", max_day);
}

