#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iterator>
#include <climits>
using namespace std;

bool is_baechoo[51][51];
int location[2501][2];
int M,N,K;

bool isExist(int loc[2]){
	if (is_baechoo[loc[0]][loc[1]])
		return true;
	else
		return false;
}

void dfs(int x, int y){
	int loc[2] = { x, y };
	if (x < 0 || x >= M){
		return;
	}
	if (y <0 || y >= N){
		return;
	}
	if (!isExist(loc)){
		return;
	}

	is_baechoo[loc[0]][loc[1]] = false;

	dfs(x-1,y);
	dfs(x+1, y);
	dfs(x, y+1);
	dfs(x, y -1);

}

int main(){
	int testcase; cin>>testcase;

	while(testcase--){
		for (int i = 0 ; i < 51 ; i++){
			for (int j = 0 ; j < 51 ; j++){
				is_baechoo[i][j] = false;
			}
		}

		scanf("%d %d %d", &M, &N, &K);
		for (int i = 0 ; i < K ; i++){
			int x,y;
			scanf("%d %d", &x, &y);
			location[i][0] = x;
			location[i][1] = y;
			is_baechoo[x][y] = true;
		}

//		for (int i = 0 ; i < M ; i++){
//			for (int j = 0 ; j< N ;j++){
//				if (is_baechoo[i][j]){
//					cout << " 1 ";
//				}
//				else{
//					cout << " 0 ";
//				}
//			}
//			cout << endl;
//		}

		int count = 0;
		for (int i = 0 ; i < K; i++){
			if (!isExist(location[i]))
				continue;
			count++;
			dfs(location[i][0], location[i][1]);
		}
		cout << count << endl;
	}

	return 0;
}



