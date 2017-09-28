/**
	Accepted
	0 is even.
*/

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

int R, C, M, N;
int W;

#define MAX_RC  100
int land[MAX_RC][MAX_RC];
bool visited[MAX_RC][MAX_RC];

vector<ii> dir;
int sz;

void process() {
	queue<ii> qu;
	qu.push(ii(0, 0));

	while (qu.size()) {
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();

		if (visited[x][y]) continue;

		for (int i = 0; i < sz; i++) {
			int new_x = x + dir[i].first;
			int new_y = y + dir[i].second;
			if (new_x >= 0 && new_y >= 0) {
				if (new_x < R && new_y < C) {
					if (land[new_x][new_y] != -1) {
						land[new_x][new_y]++;
						if (!visited[new_x][new_y])
							qu.push(ii(new_x, new_y));
					}
				}
			}
		}
		visited[x][y] = true;
	}
}

int main() {
	fp = fopen("res.txt", "w");
	int test_case; cin >> test_case;
	int num = 1;
	while(test_case--) {
		cin >> R >> C >> M >> N;
		dir.clear();
		if (M == 0 || N == 0) {
			sz = 4;
			if (N == 0) {
				N = M;
			}
			dir.push_back(ii(N, 0));
			dir.push_back(ii(-N, 0));
			dir.push_back(ii(0, N));
			dir.push_back(ii(0, -N));
		}
		else if (M == N) {
			sz = 4;
			dir.push_back(ii(N, N));
			dir.push_back(ii(-N, N));
			dir.push_back(ii(N, -N));
			dir.push_back(ii(-N, -N));
		}
		else {
			sz = 8;
			dir.push_back(ii(M, N));
			dir.push_back(ii(-M, N));
			dir.push_back(ii(M, -N));
			dir.push_back(ii(-M, -N));

			dir.push_back(ii(N, M));
			dir.push_back(ii(-N, M));
			dir.push_back(ii(N, -M));
			dir.push_back(ii(-N, -M));
		}

		memset(land, 0, sizeof(land));
		memset(visited, false, sizeof(visited));

		cin >> W;
		for (int i = 0; i < W; i++) {
			int x, y;
			cin >> x >> y;
			land[x][y] = -1;
		}

		process();
		int even = 0, odd = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				//cout << land[i][j] << " ";
				if (visited[i][j] && land[i][j] >= 0) {
					if (land[i][j] & 1) odd++;
					else even++;
				}
			}
			//cout << endl;
		}
		fprintf(stdout, "Case %d: %d %d\n", num, even, odd);
		num++;
	}
	return 0;
}
