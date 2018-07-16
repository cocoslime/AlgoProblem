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

double dist[MAXN];
int N;
double coord[MAXN][2];
double adjMat[MAXN][MAXN]; // 0 : source, 1 : destination

void dijkstra(){
    bool checked[MAXN] = {0};
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    pq.push(make_pair(0.0, 0));
    dist[0] = 0;
    while (!pq.empty()){
        int src = pq.top().second;
        double src_cost = pq.top().first;

        pq.pop();
        if (checked[src]) continue;
        checked[src] = true;
        for (int i = 0 ; i < N + 2 ; i++){
            if (adjMat[src][i] > 0){ // connected
                double cost = adjMat[src][i];
                if (dist[src] + cost < dist[i]){
                    dist[i] = dist[src] + cost;
                    pq.push(make_pair(dist[i], i));
                }
            }
        }
        /*
        for (auto pi : adjList[src]){
            int dest = pi.second;
            int w = pi.first;
            if (dist[src] + w < dist[dest]){
                dist[dest] = dist[src] + w;
                pq.push(make_pair(-(dist[src] + w), dest));
            }
        }
         */
    }
}

double calcCost(int i, int j){
    double i_x = coord[i][0];
    double i_y = coord[i][1];

    double j_x = coord[j][0];
    double j_y = coord[j][1];

    double dist = sqrt((i_x - j_x) * (i_x - j_x) + (i_y - j_y) * (i_y - j_y));

    if (dist >= 50.0){
        double cost = 2.0 + (dist - 50.0) / 5.0;
        return cost;
    }
    else{
        double walk_cost = dist / 5.0;
        double cannon_cost = 2.0 + (50.0 - dist) / 5.0;
        return min(walk_cost, cannon_cost);
    }
}

void makeGraph(){
    for (int i = 0 ; i < N + 1; i++){
        for (int j = i + 1; j < N + 2 ; j++){
            double cost = calcCost(i, j);
            adjMat[i][j] = cost;
            adjMat[j][i] = cost;
        }
    }
}

int main(){
    cin >> coord[0][0] >> coord[0][1];
    cin >> coord[1][0] >> coord[1][1];

    adjMat[0][0] = -1;
    adjMat[1][1] = -1;

    cin >> N;

    for (int i = 0 ; i < N ; i++){
        cin >> coord[i + 2][0] >> coord[i+2][1];
        adjMat[i+2][i+2] = -1;
    }

    makeGraph();

    std::fill(dist, dist + MAXN, INF);

    dijkstra();

    printf("%f\n", dist[1]);
    return 0;
}