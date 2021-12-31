#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAX_N 102
int N;
int arr[MAX_N][MAX_N];


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

int bfs(int height) {
    bool checked[MAX_N][MAX_N] = {0};

    int total = 0;
    for (int i = 0 ; i < N ; i ++){
        for (int j  = 0 ; j < N ; j++){
            if (!checked[i][j] && arr[i][j] > height){
                queue<area> qu;
                qu.push(area(i, j));
                while (!qu.empty()){
                    area curr = qu.front();
                    qu.pop();
                    if (checked[curr.x][curr.y])
                        continue;
                    checked[curr.x][curr.y] = true;
                    for (auto& di : dir){
                        int nx = curr.x + di[0];
                        int ny = curr.y + di[1];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;
                        if (arr[nx][ny] > height){
                            qu.push(area(nx, ny));
                        }
                    }
                }
                total++;
            }
        }
    }
   // cout << total << endl;
    return total;
}

int main() {
    int max_height = -1;
    cin >> N;
    for (int i = 0; i < N ; i++) {
        for (int k = 0; k < N; k++) {
            cin >> arr[i][k];
            if (arr[i][k] > max_height) {
                max_height = arr[i][k];
            }
        }
    }

    int result = 1;
    for (int i = 1; i <= max_height; i++) {
        int bfs_value = bfs(i);
        // cout << i << " : " << now << endl;
        if (result < bfs_value)
            result = bfs_value;
        // answer = max(answer, now);
    }
    printf("%d\n", result);
}