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

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define INF 1000000000

#include <iostream>
#include <fstream>

ofstream fout("res.txt");
FILE* fp;

int N, M;
int price[1000];
vector<vector<ii>> adjList;

int cost[1000][101];
int src, dest;
int C;

struct edge {
	int i, g, w;
	edge() {}
	edge(int I, int G, int W) : i(I), g(G), w(W) {}
	bool operator < (const edge &that) const {
		return w > that.w;
	}
};


int dijkstra() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= C; j++) {
			cost[i][j] = INT_MAX;
		}
	}
	priority_queue<edge> pq;
	pq.push(edge(src, 0,0));
	cost[src][0] = 0;

	while (!pq.empty()) {
		edge curr_pair = pq.top();
		pq.pop();

		int curr_cost = curr_pair.w;
		int curr_city = curr_pair.i;
		int curr_fuel = curr_pair.g;

		if (curr_city == dest) return curr_cost;

		if (cost[curr_city][curr_fuel] < curr_cost) continue;
		
		if (curr_fuel + 1 <= C && curr_cost + price[curr_city] < cost[curr_city][curr_fuel+1]) {
			cost[curr_city][curr_fuel + 1] = curr_cost + price[curr_city];
			pq.push(edge(curr_city, curr_fuel + 1, curr_cost + price[curr_city]));
		}
		for (int i = 0; i < adjList[curr_city].size(); i++) {
			int adj_dist = adjList[curr_city][i].first;
			int adj_city = adjList[curr_city][i].second;
			if (adj_dist <= curr_fuel) {
				int new_fuel = curr_fuel - adj_dist;
				if (curr_cost < cost[adj_city][new_fuel]) {
					cost[adj_city][new_fuel] = curr_cost;
					pq.push(edge(adj_city, new_fuel, curr_cost));
				}
				
			}
		}
	}

	return INT_MAX;

}

int main() {
	fp = fopen("res.txt", "w");
	cin >> N >> M;
	adjList.clear();
	adjList.assign(N, vector<ii>());

	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}

	for (int i = 0; i < M;i++) {
		int u, v;
		int dist;
		cin >> u >> v >> dist;
		adjList[u].push_back(ii(dist, v));
		adjList[v].push_back(ii(dist, u));
	}

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> C >> src >> dest;
		int ret = dijkstra();
		if (ret == INT_MAX) fprintf(stdout, "impossible\n");
		else fprintf(stdout, "%d\n", ret);
	}

	return 0;
}
