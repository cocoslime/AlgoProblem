
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
ifstream fin("input.txt");
FILE* fp;

#define MAX_N 500

int left_cache[MAX_N][MAX_N];
int right_cache[MAX_N][MAX_N];
bool bob[MAX_N][MAX_N];

int N;

void print();

int dp_left(int y_index, int x_index) {
	if (y_index >= N || x_index >= N || y_index < 0 || x_index < 0) return 0;
	
	if (left_cache[y_index][x_index] != -1) return left_cache[y_index][x_index];

	int& ret = left_cache[y_index][x_index];
	ret = 0;
	if (bob[y_index][x_index]) ret += 1;
	ret += max(dp_left(y_index - 1, x_index) , dp_left(y_index, x_index - 1));
	return ret;
}

int dp_right(int y_index, int x_index) {
	if (y_index >= N || x_index >= N || y_index < 0 || x_index < 0) return 0;

	if (right_cache[y_index][x_index] != -1) return right_cache[y_index][x_index];

	int& ret = right_cache[y_index][x_index];
	ret = 0;
	if (bob[y_index][x_index]) ret += 1;
	ret += max(dp_right(y_index, x_index + 1) , dp_right(y_index -1, x_index));
	return ret;
}

int main() {
	int test_case; 
	fin >> test_case;

	while (test_case--) {
		fin >> N;
		for (int i = N -1 ; i >=  0; i--) {
			for (int j = 0; j < N ; j++) {
				left_cache[i][j] = -1;
				right_cache[i][j] = -1;
				char c;
				fin >> c;
				if (c == '_') bob[i][j] = false;
				else if (c == 'B') bob[i][j] = true;
			}
		}

		dp_left( N-1 , N- 1);
		dp_right(N - 1, 0 );
		
		int max_ret = 0;

		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < N - 1; j++) {
				int temp = left_cache[i][j] + right_cache[i][j + 1];
				if (max_ret < temp) {
					max_ret = temp;
				}
			}
		}


		fout << max_ret << endl;
	}
	return 0;

}

void print() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			cout << bob[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N - 1; j++) {
			printf("(%d,%d) ", left_cache[i][j], right_cache[i][j + 1]);
		}
		cout << endl;
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			cout << left_cache[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			cout << right_cache[i][j] << " ";
		}
		cout << endl;
	}
}