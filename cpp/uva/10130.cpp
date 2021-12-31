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

#define REP(i, a, b) for (int i = int(a) ; i < int(b); i++)

#include <iostream>

int T, N, G;
int price[1001];
int weight[1001];
int cache[31][1001];
int maxWeight;

int value(int rem, int index) {
	if (rem < 0) return 0;
	if (index == N) return 0;
	if (cache[rem][index] >= 0) return cache[rem][index];
	int ret = max(value(rem, index + 1), price[index] + value(rem - weight[index], index + 1));
	cout << rem << " , " << index << " : " << ret << endl;
	cache[rem][index] = ret;
	return ret;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> price[i] >> weight[i];
		}

		for (int i = 0; i < 31; i++) {
			std::fill(begin(cache[i]), end(cache[i]), -1);
		}

		cin >> G;
		int total = 0;
		while (G--) {
			cin >> maxWeight;
			total += value(maxWeight, 0);
		}
		printf("---%d\n", total);
		for (int i = 0; i <= maxWeight; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", cache[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}