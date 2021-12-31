//
// Created by stem_dong on 2018-08-09.
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

#define MAX_N 200

vii coords;
vector<vi> adjList;

int N;

int calc_dist(pair<int, int> &xy, int sx, int sy);

void bfs();

int main(){
    int test_case; cin >> test_case;
    bool first = true;
    while (test_case--){
        if (!first){
            printf("\n");
        }
        first = false;
        coords.clear();
        adjList.clear();
        cin >> N;
        adjList.assign(N+2, vi());

        int sx, sy;
        cin >> sx >> sy;
        coords.emplace_back(sx, sy);
        for (int i = 0 ; i < N ; i++){
            cin >> sx >> sy;
            for (int j = 0 ; j < coords.size() ; j++){
                if (calc_dist(coords[j], sx, sy) <= 1000){
                    adjList[j].emplace_back(coords.size());
                    adjList[coords.size()].emplace_back(j);
                }
            }
            coords.emplace_back(sx, sy);
        }
        cin >> sx >> sy;
        for (int j = 0 ; j < coords.size() ; j++){
            if ( calc_dist(coords[j], sx, sy) <= 1000){
                adjList[j].emplace_back(coords.size());
                adjList[coords.size()].emplace_back(j);
            }
        }
        coords.emplace_back(sx, sy);

        bfs();
    }
}

void bfs() {
    bool checked[MAX_N] = {0};
    queue<int> qu;
    qu.push(0);
    while (!qu.empty()){
        int curr = qu.front();
        qu.pop();
        if (curr == N + 1){
            printf("happy");
            return;
        }
        if (checked[curr]) continue;
        checked[curr] = true;

        for (int ni : adjList[curr]){
            if (!checked[ni])
                qu.push(ni);
        }
    }
    printf("sad");
}

int calc_dist(pair<int, int> &xy, int sx, int sy) {
    int dist = abs(xy.first - sx) + abs(xy.second - sy);
    return dist;
}