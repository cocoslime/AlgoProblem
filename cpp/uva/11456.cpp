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

int num;
int N[2001];
int LIS[2001];
//int L_id[2001];


int LDS[2001];
//int L2_id[2001];

int compare(int a, int b) {
	return a > b;
}

int main() {
	int test_case; cin >> test_case;

	while (test_case--) {
		int result = 0;
		cin >> num;
		int length = 0;
		int length_lds = 0;
		for (int i = num - 1; i >= 0; i--) {
			cin >> N[i];
		}
		for (int i = 0; i < num; i++) {
			int pos = lower_bound(LIS, LIS + length, N[i]) - LIS;
			LIS[pos] = N[i];

			if (pos + 1 > length) {
				length = pos + 1;
			}

			int pos2 = upper_bound(LDS, LDS + length_lds, N[i], compare) - LDS;
			/*for (pos2 = length_lds ; pos2 > 0; pos2--) {
				if (LDS[pos2 - 1] > N[i]) break;
			}*/
			LDS[pos2] = N[i];

			if (pos2 + 1 > length_lds) {
				length_lds = pos2 + 1;
			}

			if (result < pos2 + pos + 2) result = pos2 + pos + 1;
			//cout << i << " : " << pos + 1 << ", " << pos2 + 1 << endl;
		}
		cout << result << endl;
	}
}