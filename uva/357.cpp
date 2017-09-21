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

int m, n;
ll cache[30001][5];
bool checked[30001][5];
int coin[5] = { 50 , 25, 10, 5 , 1 };

ll func(int remain, int index) {
	if (remain == 0) return 1;
	if (index == 5) return 0;
	if (checked[remain][index]) return cache[remain][index];

	checked[remain][index] = true;
	ll& ret = cache[remain][index];
	ret = 0;

	int i = 0;
	while (true) {
		if (remain - coin[index] * i < 0) break;
		ret += func(remain - coin[index] * i, index + 1);
		i++;
	}

	return ret;
}

int main() {
	fp = fopen("res.txt", "w");
	memset(checked, false, sizeof(checked));
	while (cin >> n)
	{
		ll ret = func(n, 0);
		if (ret == 1) {
			fprintf(stdout, "There is only %lld way to produce %d cents change.\n", ret, n);
		}
		else {
			fprintf(stdout, "There are %lld ways to produce %d cents change.\n", ret, n);
		}
	}
}