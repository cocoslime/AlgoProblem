#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define REP(i, a, b) for (int i = int(a) ; i < int(b); i++)

#include <iostream>

int num = 0; 
long long arr[101];
long long cache[101][101];


long long findsubMax(int s, int e) {
	if (e - s == 1) return arr[s];
	if (cache[e - 1] / cache[s] < 0) {
		return max(findsubMax(s, e - 1), findsubMax(s + 1, e));
	}
	else {
		return cache[e - 1] / cache[s];
	}
}

long long findMax(int s, int e) {
	if (e - s == 1) return arr[s];
	if (e == s) return 0;
	int i = 0;
	for (i = s; i < e; i++) {
		if (arr[i] == 0) {
			break;
		}
	}
	if (i == e){
		if (cache[e - 1] > 0) return cache[e - 1];
		else {
			return findsubMax(s, e);
		}
	}
	else {
		return max((long long)0, max(findMax(s, i), findMax(i + 1, e)) );
	}
}

int main() {
	int value;
	
	while (scanf("%d", &value) == 1) {
		if (value != -999999) {
			arr[num] = value;
			num++;
		}
		else {
			for (int i = 0; i < num; i++) {
				fill(begin(cache[i]), end(cache[i]), -1);
			}
			cout << findMax(0, num) << endl;
			num = 0;
		}
	}
	
	return 0;
}