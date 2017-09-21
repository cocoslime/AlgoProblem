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


int road[20002];
int N, S;

int max_i, max_j;
int max_value = 0;

int temp_i, temp_j;
int value;


int main() {
	cin >> N;
	int r = 1;
	while (N--) {
		cin >> S;
//		std::fill(begin(cache), end(cache), -1);
		max_i = 0;
		max_j = 0;
		max_value = 0;

		temp_i = 0; temp_j = 0;
		value = 0;
		for (int i = 0; i < S - 1; i++) {
			cin >> road[i];
		}
		int index = 0;
		while (index < S - 1) {
			value = value + road[index];
			if (value < 0) {
				value = 0;
				temp_i = index + 1;
				temp_j = index + 1;
			}
			else {
				temp_j = index + 1;
				if (value > max_value) {
					max_value = value;
					max_i = temp_i;
					max_j = temp_j;
				}
				else if (value == max_value) {
					if (temp_j - temp_i > max_j - max_i) {
						max_i = temp_i;
						max_j = temp_j;
					}
				}
			}
			index++;
		}

		if (max_i == 0 && max_j == 0) {
			printf("Route %d has no nice parts\n", r);
		}
		else {
			printf("The nicest part of route %d is between stops %d and %d\n", r, max_i + 1, max_j + 1);
		}
		r++;
	}
	return 0;
}