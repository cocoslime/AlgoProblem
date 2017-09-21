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


#include <iostream>


int main() {
	int H, U, D, F;
	while (true) {
		cin >> H >> U >> D >> F;
		if (H == 0) break;

		double distance = U;
		double factor = distance * (double)F / 100.0;
		int day = 0;
		double snail = 0.0;
		while (day == 0 || snail >= 0) {
			day++;
			snail += distance;
			if (snail > H) break;

			snail -= D;
			distance -= factor;
			if (distance < 0) distance = 0;
		}

		if (snail > 0) cout << "success on day " << day << endl;
		else cout << "failure on day " << day << endl;

	}

	return 0;
}