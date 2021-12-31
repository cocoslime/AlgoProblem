//
// Created by Dong's MacBook Pro on 2018. 6. 11..
//

#include <cstdio>
#include <queue>

using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

struct node{
    int x,y,w;
    node(int x, int y, int w) : x(x), y(y), w(w) {}
    bool operator <(node A)const { return w > A.w; }
};

int main(){
    int M, N;

    char maze_map[105][105];
    int checked[105][105] = {0};
    scanf("%d %d\n", &M, &N);

    for (int i = 0; i < N ; i++){
        scanf("%s", maze_map[i]);
        //cin >> maze_map[i];
    }

    priority_queue<node> pq;
    pq.push(node(0,0,0));

    while(!pq.empty()){
        int curr_cost = pq.top().w;
        int curr_x = pq.top().x;
        int curr_y = pq.top().y;

        pq.pop();

        if (curr_x == N-1 && curr_y == M-1){
            printf("%d", curr_cost);
            break;
        }
        checked[curr_x][curr_y] = 1;

        for (int di = 0 ; di < 4; di++){
            int next_x = curr_x + dx[di];
            int next_y = curr_y + dy[di];
            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || checked[next_x][next_y])
                continue;

            int next_cost = maze_map[next_x][next_y] == '1' ? 1 : 0;
            pq.push(node(next_x, next_y, curr_cost + next_cost));
        }

    }

    return 0;
}
