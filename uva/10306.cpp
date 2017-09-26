#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
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

int cache[301][301];
bool checked[301][301];
int coin[41][2];

int m, s;
int sq_s;

int func(int x, int y) {
	if (x > s || y > s) {
		return 3000;
	}
	if (sq_s < x * x + y * y) return 3000;
	if (sq_s == x * x + y * y) return 0;

	if (checked[x][y]) return cache[x][y];
	checked[x][y] = true;

	int &ret = cache[x][y];
	ret = 3000;
	for (int i = 0; i < m; i++) {
		ret = min(func(x + coin[i][0], y + coin[i][1]), ret);
	}
	ret += 1;
	return ret;

}

int main() {
	fp = fopen("res.txt", "w");
	int test_case; cin >> test_case;

	while (test_case--) {
		cin >> m >> s;
		sq_s = s * s;
		memset(checked, 0, sizeof(checked));
		for (int i = 0; i < m; i++) {
			cin >> coin[i][0] >> coin[i][1];
		}
		int ret = func(0,0);
		if (ret > s) cout << "not possible" << endl;
		else printf("%d\n", ret);
	}


}