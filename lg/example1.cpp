
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

#define INF 1000000000

#include <iostream>
#include <fstream>

ofstream fout("res.txt");
FILE* fp;

#define DP_MAX 32768 // 2^15

ll twopow[61];
ll dp[61];

ll y_div = 1, x_div = 1;
int x_digit = 1, y_digit = 1;
int findDigit(ll);

ll func_back(ll e) {
	if (e == 0) return 0;
	if (e == 1) return 1;
	int digit = findDigit(e);
	ll div = twopow[digit - 1];
	return func_back(e - div) + dp[digit -1 ];
}

ll func_front(ll s, int s_digit) {
	return dp[s_digit] - func_back(s);
}

ll func_center_digit(int s_digit, int e_digit) {
	if (s_digit == e_digit) return 0;
	return dp[e_digit] - dp[s_digit];
}


int findDigit(ll num) {
	int digit = 1;
	for (int i = 60; i >= 0; i--) {
		if (twopow[i] <= num) return i + 1;
	}
}

void setArray() {
	ll multiple = 1;
	twopow[0] = multiple;
	multiple *= 2;
	dp[0] = 1;
	
	for (int i = 1; i <= 60; i++) {
		twopow[i] = multiple;
		multiple *= 2;
		dp[i] = dp[i - 1] * 2 + 1;
	}
}

int main() {
	memset(dp, 0, sizeof(dp));

	setArray();
	int test_case; 
	fscanf(stdin, "%d", &test_case);
	while (test_case--) {
		ll x, y;
		scanf("%lld %lld", &x,&y);

		x_digit = findDigit(x);
		y_digit = findDigit(y);
		x_div = twopow[x_digit - 1];
		y_div = twopow[y_digit - 1];

		//cout << x_div << ", " << x_digit << endl;
		//cout << y_div << ", " << y_digit << endl;

		ll ret;
		while (x_digit == y_digit) {
			x = x - x_div;
			y = y - y_div;
			x_digit = findDigit(x);
			y_digit = findDigit(y);
			x_div = twopow[x_digit - 1];
			y_div = twopow[y_digit - 1];
		}
		if (x_digit < y_digit) {
			ret = func_front(x, x_digit);
			ret += func_center_digit(x_digit, y_digit - 1);
			ret += func_back(y - y_div);
		}

		fout << ret << endl;
	}

}