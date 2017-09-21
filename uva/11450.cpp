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

int cache[201][21];
int price[25][25];
int N;
int M, C, K;

int rec(int remain, int index) {
	if (remain < 0) return -1;
	if (cache[remain][index] != -1) return cache[remain][index];
	if (index == C) return 0;

	int ret = -1;
	for (int i = 1; i <= price[index][0]; i++) {
		int temp = rec(remain - price[index][i], index + 1);
		if (temp != -1) ret = max(ret, price[index][i] + temp);
		//ret = max(ret, price[index][i] + rec(remain - price[index][i], index + 1) );
	}
	if (ret == -1) return -1;

	cache[remain][index] = ret;
	return ret;
}

int main() {
	cin >> N;
	while (N--) {
		cin >> M >> C;
		for (int i = 0; i <= M; i++) {
			//memset(cache[i], 0, sizeof(cache[i]));
			std::fill(begin(cache[i]), end(cache[i]), -1);
		}

		for (int i = 0; i < C; i++) {
			cin >> K;
			price[i][0] = K;
			for (int j = 1; j <= K; j++) {
				cin >> price[i][j];
			}
		}

		int result = rec(M, 0);
		if (result != -1) cout << result << endl;
		else cout << "no solution" << endl;

	}
	return 0;
}