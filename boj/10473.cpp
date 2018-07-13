//
// Created by dongmin on 18. 7. 2.
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

#define MAXN 103

int S;
int V, E;
int dist[MAXV];

double adjMat[MAXN][MAXN]; // 0 : source, 1 : destination

void dijkstra(){
    bool checked[MAXV] = {0};
    priority_queue<ii> pq;
    pq.push(make_pair(0, S));
    dist[S] = 0;
    checked[S] = true;
    while (!pq.empty()){
        int src = pq.top().second;
        pq.pop();
        if (checked[src]) continue;
        checked[src] = true;
        for (auto pi : adjList[src]){
            int dest = pi.second;
            int w = pi.first;
            if (dist[src] + w < dist[dest]){
                dist[dest] = dist[src] + w;
                pq.push(make_pair(-(dist[src] + w), dest));
            }
        }
    }
}

int main(){
    cin >> V >> E;
    int start;
    cin >> start;

    S = start - 1;

    adjList.assign(V, vii());

    std::fill(dist, dist + MAXV, INF);

    for (int i = 0 ; i < E ; i++){
        int src, dest, w;
        cin >> src >> dest >> w;
        adjList[src-1].emplace_back(w, dest - 1);
    }

    dijkstra();

    for (int i = 0 ; i < V ; i++){
        if (dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
    return 0;
}