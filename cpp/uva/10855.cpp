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

#define MAX 500
int n1, n2;
char big_square[MAX][MAX];
char small_square[MAX][MAX];
char rotate_square[MAX][MAX];
int main() {
	//std::ifstream in("in.txt");
	//std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	//std::cin.rdbuf(in.rdbuf());

	while (cin >> n1 >> n2, n1 || n2) {
		for (int i = 0; i < n1;i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < n1; j++) {
				big_square[i][j] = temp[j];
			}
		}

		for (int i = 0; i < n2;i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < n2; j++) {
				small_square[i][j] = temp[j];
			}
		}

		
		for (int i = 0; i < 4; i++) {

			//check same
			int count = 0;
			for (int bi = 0; bi <= n1 - n2; bi++) {
				for (int bj = 0; bj <= n1 - n2; bj++) {
					bool same = true;
					for (int si = 0; si < n2; si++) {
						for (int sj = 0; sj < n2; sj++) {
							if (big_square[bi+si][bj+sj] != small_square[si][sj]) {
								same = false;
								break;
							}
						}
						if (!same) break;
					}
					if (same) count++;
				}
			}
			
			//print
			printf("%d", count);
			if (i != 3) printf(" ");
			
			//rotate
			for (int ii = 0; ii < n2; ii++) {
				for (int jj = 0; jj < n2;jj++) {
					rotate_square[jj][n2 -1-ii] = small_square[ii][jj];
				}
			}

			for (int ii = 0; ii < n2; ii++) {
				for (int jj = 0; jj < n2;jj++) {
					small_square[ii][jj] = rotate_square[ii][jj];
				}
			}

			//printf("\n");
			//for (int ii = 0; ii < n; ii++) {
			//	for (int jj = 0; jj < n;jj++) {
			//		cout << small_square[ii][jj] << " ";
			//	}
			//	cout << endl;
			//}


		}
		printf("\n");

	}
	return 0;
}