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

#define INF 1000000000

#include <iostream>
#include <fstream>

ofstream fout("res.txt");
FILE* fp;

int M, N, S;
int arena[101][101];

int total_stickers = 0;

ii curr_pos;
int curr_ori; // N O S L

ii dir[4] = { { -1, 0 },{ 0, 1 },{ 1, 0 },{ 0, -1 } };

int main() {
	while (cin >> N >> M >> S) {
		if (N == 0 && M ==0 && S == 0) break;
		total_stickers = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				char c;
				cin >> c;
				if (c == '.') {
					arena[i][j] = 0;
				}
				else if (c == '*') {
					arena[i][j] = 1;
					total_stickers++;
				}
				else if (c == '#') {
					arena[i][j] = -1;
				}
				else {
					arena[i][j] = 0;
					if (c == 'N') curr_ori = 0;
					if (c == 'L') curr_ori = 1;
					if (c == 'S') curr_ori = 2;
					if (c == 'O') curr_ori = 3;
					curr_pos.first = i;
					curr_pos.second = j;
				}
			}
		}

		int score = 0;
		for (int i = 0; i < S; i++) {
			char c;
			cin >> c;
			if (c == 'F') {
				int n_i = curr_pos.first + dir[curr_ori].first;
				int n_j = curr_pos.second + dir[curr_ori].second;

				if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M) {
					if (arena[n_i][n_j] == -1) {

					}
					else { //move
						//cout << curr_ori << " curr : " << curr_pos.first << ", " << curr_pos.second << " -> ";
						//cout << "next : " << n_i << ", " << n_j << endl;
						if (arena[n_i][n_j] == 1) {
							score++;
							//cout << " scored ! " << endl;
						}
						arena[n_i][n_j] = 0;
						curr_pos.first = n_i;
						curr_pos.second = n_j;
					}
				}
				else { //Dont move

				}
			}
			else if (c == 'E') { //left
				//cout << "left" << curr_ori << endl;
				curr_ori--;
				if (curr_ori < 0) curr_ori = 3;
			}
			else if (c == 'D') { //right
				//cout << "right" << endl;
				curr_ori++;
				if (curr_ori > 3) curr_ori = 0;
			}
		}
		cout << score << endl;
	}

	return 0;
}