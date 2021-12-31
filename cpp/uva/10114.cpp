#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define REP(i, a, b) for (int i = int(a) ; i < int(b); i++)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

double decP[101];

int main() {
	while (1) {
		int months, records;
		double down_payment, price;
		//scanf("%d %lf %lf %d", &months, &down_payment, &price, &records);
		cin >> months >> down_payment >> price >> records;
		if (months < 0) break;

		double own = price;
		double monthly_pay = price / months;
		int m; double de;
		for (int i = 0; i < records; i++) {
			cin >> m >> de;
			for (int j = m; j < 101; j++) {
				decP[j] = de;
			}
		}

		int month = 0;
		double dec = 1 - decP[0];
		double car_price = (price + down_payment) * dec;
		
		while (own > car_price) {
			month++;
			dec = 1 - decP[month];
			car_price = car_price * dec;
			own -= monthly_pay;
		}

		if (month == 1) cout << month << " month" << endl;
		else cout << month << " months" << endl;
	}
	return 0;
}