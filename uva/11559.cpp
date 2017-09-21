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
	int participants, budget, hotels, weeks;
	while (scanf("%d %d %d %d", &participants, &budget, &hotels, &weeks) == 4) {
		int min_budget = INT_MAX;
		while (hotels--) {
			int price; cin >> price;
			for (int i = 0; i < weeks; i++) {
				int beds; cin >> beds;
				if (beds < participants) continue;
				if (participants * price > budget) continue;
				min_budget = min(min_budget, participants * price);
			}
		}
		if (min_budget == INT_MAX) cout << "stay home" << endl;
		else cout << min_budget << endl;
	}
	return 0;
}