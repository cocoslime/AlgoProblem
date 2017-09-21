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

#define REP(i, a, b) for (int i = int(a) ; i < int(b); i++)

#include <iostream>
#include <fstream>

ofstream fout("res.txt");
FILE* fp;

int m, n;
int price[101];
int favour[101];

int cache[101][10201];
bool v[101][10201];

int func(int pos, int money) {
	
	if (pos == n) {
		if (money <= m || money > 2000 && money <= m + 200)
			return 0;
		else
			return -10000;
	}
	int &ret = cache[pos][money];

	if (v[pos][money]) return cache[pos][money];
	v[pos][money] = true;
	
	int increase = money + price[pos];

	if (increase <= m + 200) {
		ret = max(func(pos + 1, money), favour[pos] + func(pos + 1, increase));
	}
	else {
		ret = func(pos + 1, money);
	}
	return ret;
}

int main() {
	fp = fopen("res.txt", "w");
	
	while (cin >> m >> n) {
		memset(v, false, sizeof(v));
		//if (m > 1800) m += 200;
		for (int i = 0; i < n; i++) {
			cin >> price[i] >> favour[i];
		}

		int total = func(0, 0);
		cout << total << endl;
	}



}