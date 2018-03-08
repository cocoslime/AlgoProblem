//
// 4장 그래프
// Maximum Flow Problem
// Created by Dong's MacBook Pro on 2018. 1. 30..
//

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
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define INF 1000000000

#define MAX_N 100

vi p;
vector<vi> adjList;
int res[MAX_N][MAX_N] = {0};

int N;
int mf, f;
int s, t, c;

FILE* fp;

void init();
void augment(int, int);

int main(){
    fp = stdout;
    //fp = fopen("result.txt", "w");

    int networkNumber = 1;
    cin >> N;
    while (N != 0){
        init();
        scanf("%d %d %d", &s,&t,&c);
        s -= 1;
        t -= 1;

        for (int i = 0 ; i < c ; i++){
            int src, dest, bd;
            scanf("%d %d %d", &src, &dest, &bd);

            res[src-1][dest-1] += bd;
            res[dest-1][src-1] += bd;
            adjList[src-1].push_back(dest-1);
            adjList[dest-1].push_back(src-1);
        }

        mf = 0;
        while (true){
            f = 0;
            bitset<MAX_N> checked; checked[s] = true;
            queue<int> qu;
            qu.push(s);

            while (!qu.empty()){
                int node = qu.front();
                qu.pop();

                for (int neighbor : adjList[node]){
                    if (!checked[neighbor] && res[node][neighbor] > 0){
                        checked[neighbor] = true;
                        p[neighbor] = node;
                        qu.push(neighbor);
                    }
                }
            }
            augment(INF, t);

            if (f == 0) break;
            mf += f;
        }

        fprintf(fp, "Network %d\n", networkNumber++);
        fprintf(fp, "The bandwidth is %d.\n\n", mf);

        cin >> N;
    }

    return 0;
}

void augment(int minFlow, int target){
    if (target == s){
        f = minFlow;
        return;
    }
    else if (p[target] != -1){
        int parent = p[target];
        minFlow = min(minFlow, res[parent][target]);
        augment(minFlow, parent);
        res[parent][target] -= f;
        res[target][parent] += f;
    }
}

void init(){
    adjList.clear();
    adjList.assign(N, vi());
    p.assign(N, -1);
    for (int i = 0; i < MAX_N ; i++){
        for (int j = 0 ; j < MAX_N ; j++){
            res[i][j] = 0;
        }
    }
}