#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define REP(i, a, b) for (int i = int(a) ; i < int(b); i++)

#include <iostream>
#include <fstream>

ofstream fout("res.txt");

ll cache[101][101];
int N, M;
ll K;

int main() {
	int test_case; cin >> test_case;
	int num = 1;
	while (test_case--) {
		cin >> N >> M;
		cin >> K;
		fill(begin(cache[0]), end(cache[0]), 0);
		for (int i = 1; i <= N; i++) {
			std:fill(begin(cache[i]), end(cache[i]), 0);
			for (int j = 1; j <= M; j++) {
				ll temp; cin >> temp;
				cache[i][j] = temp + cache[i][j - 1] + cache[i - 1][j] - cache[i - 1][j - 1];
			}
		}

		ll ans_price = 0;
		int ans_area = 0;
		for (int si = 0; si < N; si++) {
			for (int sj = 0; sj < M; sj++) {
				/*if (si != sj) {
					if (si == 0 || sj == 0) continue;
				}*/
				for (int ei = si + 1; ei <= N; ei++) {
					for (int ej = sj + 1; ej <= M; ej++) {
						ll price = cache[ei][ej];
						if (si != 0) price -= cache[si][ej];
						if (sj != 0) price -= cache[ei][sj];
						if (sj != 0 && si != 0) price += cache[si][sj];
						if (price > K) break;
						int area = (ei - si) * (ej - sj);
						if (area > ans_area) {
							ans_price = price;
							ans_area = area;
						}
						else if (area == ans_area) {
							if (price < ans_price)
								ans_price = price;
						}
					}
				}
			}
		}
		cout << "Case #" << num << ": " << ans_area << " " << ans_price << endl;
		
		num++;
	}
	return 0;
}