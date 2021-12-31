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

int N,x,T,K;

int total_dish;


int price[201];
int favour[201];

bool checked[201][1001][21];
int cache[201][1001][21];

int func(int dim, int money, int dishes) {
	int pre_money = (money + T * N) + ceil((money + T * N) * 0.1);
	if (pre_money > x * N) return -INF;
	
	if (dishes > 2 * N) return -INF;
	if (pre_money == x* N || dim == K) return 0;
	if (checked[dim][money][dishes]) return cache[dim][money][dishes];
	
	checked[dim][money][dishes] = true;
	int ret = max(func(dim + 1, money, dishes), favour[dim] + func(dim + 1, money + price[dim], dishes + 1));

	cache[dim][money][dishes] = ret;
	return ret;
}

int main() {
	fp = fopen("res.txt", "w");
	while (cin >> N >> x >> T >> K) {
		if (N == 0 && x == 0 && T == 0 && K == 0) break;
		N += 1;

		memset(checked, false, sizeof(checked));
		total_dish = 0;
		
		for (int i = 0; i < K; i++) {
			cin >> price[i];
			favour[i] = 0;
			favour[i + K] = 0;
			price[i + K] = price[i];
			for (int j = 0; j < N; j++) {
				int temp; cin >> temp;
				favour[i] += temp;
				favour[i + K] += temp;
			}
		}
		K *= 2;
		int total_favour = func(0, 0, 0);
		fprintf(stdout, "%.2f\n", (double)total_favour / (double)N);
	}

}