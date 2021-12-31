#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
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
	int N, P;
	int index = 1;
	string temp;
	string name, best_name;
	while (true) {
		
		cin >> N >> P;
		if (N == 0 && P == 0) break;

		cin.ignore();
		for (int i = 0; i < N; i++) {
			getline(cin, temp);
		}

		double best_price = 200000000;
		int best_num = -1;
		double price;
		int num;
		while (P--){
			getline(cin, name);
			scanf("%lf %d", &price, &num);
			cin.ignore();

			for (int j = 0; j < num; j++) {
				getline(cin, temp);
			}

			if (best_num < num) {
				best_num = num;
				best_price = price;
				best_name = name;
			}
			else if (best_num == num){
				if (best_price > price) {
					best_price = price;
					best_name = name;
				}
			}
		}

		if (index != 1) printf("\n");
		printf("RFP #%d\n", index);
		printf("%s\n", best_name.c_str());
		
		index++;
	}

	return 0;
}