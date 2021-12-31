//
// Created by stem_dong on 2018-08-08.
//

#include <iostream>
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

#define MAX_N 300

int N, M;
int **arr;

int check_two();

bool melt();

class area{
public:
    int x;
    int y;
    area(int x, int y) : x(x), y(y){}
};

int dir[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
};

int main(){
    cin >> N >> M;
    arr = new int*[N];

    for (int i = 0 ; i < N ; i++){
        arr[i] = new int[M];
        for (int j = 0 ; j < M ; j++){
            cin >> arr[i][j];
        }
    }

    int year = 0;
    while (true){
        int component = check_two();
        if (component >= 2){
            printf("%d\n", year);
            return 0;
        }
        if (component == 0){
            printf("0");
            return 0;
        }

        melt();
        year++;
    }

    return 0;
}

bool melt() {
    int **old;
    old = new int*[N];
    for (int i = 0 ; i < N ; i++) {
        old[i] = new int[M];
        for (int j = 0; j < M; j++) {
            old[i][j] = arr[i][j];
        }
    }

    int zero = 0;
    for (int i = 1 ; i < N - 1 ; i++) {
        for (int j = 1; j < M - 1; j++) {
            for (auto& di:dir){
                if (arr[i][j] == 0) {
                    zero++;
                    break;
                }
                int x = i + di[0];
                int y = j + di[1];
                if (old[x][y] == 0){
                    arr[i][j] -= 1;
                }
            }
        }
    }

    delete[] old;
    return (zero == N * M);
}

int check_two() {
    int checked[MAX_N][MAX_N] = {0};
    int result = 0;
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < M ; j++){
            if (arr[i][j] != 0 && !checked[i][j]){
                queue<area> qu;
                qu.push(area(i, j));
                while (!qu.empty()) {
                    area curr = qu.front();
                    qu.pop();
                    if (checked[curr.x][curr.y])
                        continue;
                    checked[curr.x][curr.y] = true;
                    for (auto &di : dir) {
                        int nx = curr.x + di[0];
                        int ny = curr.y + di[1];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (arr[nx][ny] != 0) {
                            qu.push(area(nx, ny));
                        }
                    }
                }
                result ++;
            }
        }
    }
    return result;
}