
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

#define INF 100000000

#include <iostream>
#include <fstream>

ofstream fout("res.txt");
FILE* fp;

int M, N, P;

int map_index = 0;
map<string, int> mapping;
vector<vi> adjList;
vi dist;

int main() {
	fp = fopen("res.txt", "w");
	fprintf(fp, "SHIPPING ROUTES OUTPUT\n");
	int test_case;
	cin >> test_case;
	int test_num = 1;
	while (test_case--) {
		fprintf(fp,"\nDATA SET  %d\n\n", test_num++);
		cin >> M >> N >> P;
		mapping.clear();
		adjList.clear();
		adjList.assign(M, vi());
		map_index = 0;
		for (int i = 0; i < M; i++) {
			string str;
			cin >> str;
			mapping[str] = map_index++;
		}
		for (int i = 0; i < N;i++) {
			string src, dest;
			cin >> src >> dest;
			adjList[mapping[src]].push_back(mapping[dest]);
			adjList[mapping[dest]].push_back(mapping[src]);
		}

		for (int i = 0; i < P; i++) {
			string src, dest;
			int ship_size;
			cin >> ship_size >> src >> dest;
			int src_i = mapping[src];
			int dest_i = mapping[dest];

			//int ret = bfs(src_i, dest_i);
			queue<int> qi;
			qi.push(src_i);

			vi dist(M, -1);
			dist[src_i] = 0;
			while (!qi.empty()) {
				int curr = qi.front(); qi.pop();
				for (int neigh = 0; neigh < adjList[curr].size(); neigh++) {
					int next = adjList[curr][neigh];
					if (dist[next] == -1) {
						qi.push(next);
						dist[next] = dist[curr] + 1;
					}
				}
				if (dist[dest_i] != -1) break;
			}

			if (dist[dest_i] == -1) {
				fprintf(fp, "NO SHIPMENT POSSIBLE\n");
			}
			else {
				fprintf(fp, "$%d\n", dist[dest_i] * ship_size * 100);
			}
		}
	}

	fprintf(fp, "\nEND OF OUTPUT\n");

	return 0;
}