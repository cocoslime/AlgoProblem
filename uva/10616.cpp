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


int arr[210];
ll cache[210][11][21];
bool v[210][11][21];

int N, Q;
int D, M;

ll func(int index, int rem, ll rest) {
	//cout << index << ", " << rem << ", " << rest << endl;
	if (rem == 0) {
		if (rest == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (index == N) return 0;

	ll &ret = cache[index][rem][rest];
	if (v[index][rem][rest]) {
		//cout << index << ", " << rem << ", " <<  rest << " : " << cache[index][rem][rest] << endl;
		return cache[index][rem][rest];
	}
	v[index][rem][rest] = true;

	ll temp = ((rest + (ll)arr[index]) % D );//((rest + (ll)arr[index]) % D + D) % D;
	if (temp < 0) cout << temp << endl;
	ret = func(index + 1, rem, rest) + func(index + 1, rem - 1, (ll)temp);
	cache[index][rem][rest] = ret;
	return ret;
}

void clearcache() {
	memset(v, false, sizeof(v));
}

int main() {	
	fp = fopen("res.txt", "w");
	int set = 1;
	while (cin >> N >> Q, N != 0 || Q != 0) {
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		fprintf(stdout, "SET %d:\n", set);
		for (int i = 0; i < Q; i++) {
			cin >> D >> M;
			clearcache();
			fprintf(stdout, "QUERY %d: %lld\n", i+1, func(0, M, 0));
		}
		set++;
	}

	
}