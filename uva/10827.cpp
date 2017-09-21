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

int N;
int arr[80][80];
int cache[152][152];

int main() {
	int test_case; cin >> test_case;
	while (test_case--) {
		cin >> N; 

		for (int i = 1; i <= N; i++) {
			std::fill(begin(cache[i]), end(cache[i]), 0);
			std::fill(begin(cache[i+N]), end(cache[i+N]), 0);
			for (int j = 1; j <= N; j++) {
				int temp; cin >> temp;
				arr[i][j] = temp;
				cache[i][j] = temp + cache[i-1][j] + cache[i][j-1] - cache[i-1][j-1];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cache[i][j + N] = arr[i][j] + cache[i - 1][j + N] + cache[i][j + N - 1] - cache[i - 1][j + N - 1];
				cache[i + N][j] = arr[i][j] + cache[i + N - 1][j] + cache[i + N][j - 1] - cache[i + N - 1][j - 1];
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cache[i + N][j + N] = arr[i][j] + cache[i + N - 1][j + N] + cache[i + N][j + N - 1] - cache[i + N - 1][j + N - 1];
			}
		}

		//for (int si = 0; si <= 2 * N; si++) {
		//	for (int sj = 0; sj <= 2 * N; sj++) {
		//		cout << cache[si][sj] << " ";
		//	}
		//	cout << endl;
		//}


		int result = -255 * 100 * 100;
		for (int si = 1; si <= 2 * N; si++) {
			for (int sj = 1; sj <= 2 * N; sj++) {
				for (int ei = si; ei <= 2 * N; ei++) {
					if (ei - si > N) break;
					for (int ej = sj; ej <= 2 * N; ej++) {
						if (ej - sj > N) break;
						if (ei == si && ej == sj) continue;
						int sum = cache[ei][ej];
						if (si != 0) sum -= cache[si][ej];
						if (sj != 0) sum -= cache[ei][sj];
						if (sj != 0 && si != 0) sum += cache[si][sj];
						//printf("%d,%d ~ %d, %d\n", si, sj, ei, ej);
						//printf("%d - %d - %d + %d\n", cache[ei][ej], cache[si][ej], cache[ei][sj], cache[si][sj]);
						//cout << sum << endl;
						result = max(sum, result);
					}
					
				}
			}
		}

		cout << result << endl;

	}
	return 0;
}
