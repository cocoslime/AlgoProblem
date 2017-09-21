#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define REP(i, a, b) for (int i = int(a) ; i < int(b); i++)

#include <iostream>

bool check[3001];
int N;

int main() {
	while (scanf("%d", &N) == 1) {
		std::fill(std::begin(check), std::end(check), false);
		int n_value = N;
		N--;
		int pre; scanf("%d", &pre);
		bool suc = true;
		while (N--) {
			int temp;
			scanf("%d", &temp);
			if (!suc) continue;
			int abs1 = abs(pre - temp);
			pre = temp;
			if (abs1 > n_value) {
				suc = false;
				continue;
			}
			if (check[abs1]) {
				suc = false;
				continue;
			}
			check[abs1] = true;
		}
		if (suc) {
			for (int i = 1; i < n_value; i++) {
				if (!check[i]) {
					suc = false;
					break;
				}
			}
			if (suc)
				cout << "Jolly" << endl;
			else
				cout << "Not jolly" << endl;
		}
		else {
			cout << "Not jolly" << endl;
		}
	}
	return 0;
}