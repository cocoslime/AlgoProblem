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
#include <fstream>

int S, B;
int L, R;
int left_arr[100001];
int right_arr[100001];

int main() {
	//std::ifstream in("in.txt");
	//std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	//std::cin.rdbuf(in.rdbuf());

	while (cin >> S >> B && S != 0 && B != 0) {
		for (int i = 0; i < S; i++) {
			left_arr[i] = i-1;
			right_arr[i] = i + 1;
		}
		while (B--) {	
			cin >> L >> R;
			L -= 1;
			R -= 1;
			
			int left_pos = left_arr[L];
			int right_pos = right_arr[R];
			if (left_pos != -1) {
				right_arr[left_pos] = right_pos;
				printf("%d ", left_pos + 1);
			}
			else {
				printf("* ");
			}

			if (right_pos != S) {
				left_arr[right_pos] = left_pos;
				printf("%d\n", right_pos + 1);
			}
			else {
				printf("*\n");
			}

		}
		printf("-\n");
	}
	
	return 0;
}