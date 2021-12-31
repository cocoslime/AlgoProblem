#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define REP(i, a, b) for (int i = int(a) ; i < int(b); i++)


int n, A[101][101], maxRect, subRect;

int main() {     // O(n^3) 1D DP + greedy (Kadane's) solution, 0.008 s in UVa
	scanf("%d", &n);                    // the dimension of input square matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
			if (j > 0) A[i][j] += A[i][j - 1];
			if (i > 0) A[i][j] += A[i-1][j];
			if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
		}
	}

	maxRect = -127 * 100 * 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = -1; k < i; k++) {
				for (int w = -1; w < j; w++) {
					subRect = A[i][j];
					if (k != -1) subRect -= A[k][j];
					if (w != -1) subRect -= A[i][w];
					if (k != -1 && w != -1) subRect += A[k][w];
					if (maxRect < subRect) maxRect = subRect;
				}
			}
		}
	}
	printf("%d\n", maxRect);


	return 0;
}
