
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <climits>
#include <queue> 
#include <functional> 
#include <stack>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

#define INF 100000000

#include <iostream>
#include <fstream>

ofstream fout("res.txt");
FILE* fp;

#define MAX_N 105
int adjMat[MAX_N][MAX_N];
vector <bool> hasNode;


void calc(int test_num) {
	for (int k = 0; k < MAX_N; k++) {
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) {
				adjMat[i][j] = min(adjMat[i][k] + adjMat[k][j], adjMat[i][j]);
			}
		}
	}

	double pair_num = 0;
	double total = 0;
	
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			if (adjMat[i][j] != INF && i != j) {
				total += adjMat[i][j];
				pair_num++;
			}
		}
	}
	//cout << total << ", " << pair_num << endl;

	printf("Case %d: average length between pages = %.3lf clicks\n", test_num, total/pair_num );

}

int main() {
	int src, dest;

	int test_case = 1;

	while (true) {
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) {
				adjMat[i][j] = INF;
			}
		}
		hasNode.assign(MAX_N, false);

		scanf("%d %d", &src, &dest);
		if (src == 0 && dest == 0) {
			break;
		}
		while (true) {
			hasNode[src - 1] = true;
			adjMat[src - 1][dest - 1] = 1;
			adjMat[src - 1][src - 1] = 0;
			adjMat[dest - 1][dest - 1] = 0;

			scanf("%d %d", &src, &dest);
			if (src == 0 && dest == 0) {
				break;
			}
		}

		calc(test_case);
		test_case++;
	}

	return 0;
}
