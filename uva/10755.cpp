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

int A, B, C;

ll arr[22][22][22];

int main() {
	int test_case; cin >> test_case;
	while (test_case--) {
		cin >> A >> B >> C;
		ll result;
		for (int i = 1; i <= A; i++) {
			for (int j = 1; j <= B; j++) {
				std::fill(begin(arr[i][j]), end(arr[i][j]), 0);
				for (int k = 1; k <= C; k++) {
					ll temp; cin >> temp;
					arr[i][j][k] = arr[i][j - 1][k] + arr[i][j][k - 1] - arr[i][j - 1][k - 1] + temp;
				}
			}
		}
		result = arr[1][1][1];
		for (int j = 0; j < B; j++) {
			for (int k = 0; k < C; k++) {
				for (int jj = j + 1; jj <= B; jj++) {
					for (int kk = k + 1; kk <= C; kk++) {
						ll sum = 0;
						ll ans = arr[1][1][1];
						for (int i = 1; i <= A; i++) {
							ll value = arr[i][jj][kk] + arr[i][j][k] - arr[i][j][kk] - arr[i][jj][k];
							sum += value;
							ans = max(sum, ans);
							if (sum < 0) sum = 0;
						}
						result = max(result, ans);

					}
				}
			}
		}

		cout << result << endl;
		if (test_case != 0) cout << endl;
	}

	return 0;
}