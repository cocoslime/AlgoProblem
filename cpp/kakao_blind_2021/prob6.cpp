//
// Created by Dongmin on 9/10/21.
//


#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <numeric>

#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

int calc_dist(const vector<vi>& currBoard, ii src, ii dest){
    if (src.first == dest.first && src.second == dest.second) return 0;

    if (src.first == dest.first){
        if (dest.second == 0 || dest.second == 3 || currBoard[dest.first][dest.second]){
            int st, ed;
            int dist = 1;
            st = min(src.second, dest.second);
            ed = max(src.second, dest.second);
            for (int i = st + 1; i < ed; i++){
                if (currBoard[src.first][i])
                    dist++;
            }
            return dist;
        }
        return abs(src.second - dest.second);
    }
    else if (src.second == dest.second){
        if (dest.first == 0 || dest.first == 3 || currBoard[dest.first][dest.second]) {
            int st, ed;
            int dist = 1;
            st = min(src.first, dest.first);
            ed = max(src.first, dest.first);
            for (int i = st + 1; i < ed; i++) {
                if (currBoard[i][src.second])
                    dist++;
            }
            return dist;
        }
        return abs(src.first - dest.first);
    }

    int a = calc_dist(currBoard, src, make_pair(src.first, dest.second))
           + calc_dist(currBoard, make_pair(src.first, dest.second), dest);

    int b = calc_dist(currBoard, src, make_pair(dest.first, src.second))
            + calc_dist(currBoard, make_pair(dest.first, src.second), dest);

    return min(a,b);
}


int bfs(const vector<vi>& curr_board, vector<vector<ii>> curr_card_loc, ii src, int card_num){
    int result = INF;

    if (card_num == 0)
        return 0;

    for (int i = 1 ; i <= 6 ; i++){
        if (curr_card_loc[i].empty())
            continue;

        vector<vector<ii>> new_card_loc(curr_card_loc);
        new_card_loc[i].clear();

        vector<vi> new_board(curr_board);
        new_board[curr_card_loc[i][0].first][curr_card_loc[i][0].second] = 0;
        new_board[curr_card_loc[i][1].first][curr_card_loc[i][1].second] = 0;

        // not empty, 두 가지 경우 다 수행
        int a = calc_dist(curr_board, src, curr_card_loc[i][0]);
        a += calc_dist(curr_board, curr_card_loc[i][0], curr_card_loc[i][1]);
        a += bfs(new_board, new_card_loc, curr_card_loc[i][1], card_num - 1);

        int b = calc_dist(curr_board, src, curr_card_loc[i][1]);
        b += calc_dist(curr_board, curr_card_loc[i][1], curr_card_loc[i][0]);
        b += bfs(new_board, new_card_loc, curr_card_loc[i][0], card_num - 1);

        result = min(result, a);
        result = min(result, b);

    }

    return result;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    int card_num = 0;

    set<int> card_set;
    vector<vector<ii>> card_map(7, vector<ii>());

    for (int i = 0 ; i < 4; i ++){
        for (int j = 0 ; j < 4 ; j ++){
            if (board[i][j] != 0){
                int card_id = board[i][j];
                card_map[card_id].emplace_back(i, j);
                card_set.insert(card_id);
            }
        }
    }

    card_num = card_set.size();
    answer = bfs(board, card_map, make_pair(r, c), card_num);
    answer += card_num * 2;

    return answer;
}


int main()
{
    vector<vi> test = {{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}};
    cout << calc_dist(test, make_pair(1,0), make_pair(2,3)) << endl;

    vector<vi> test2 = {{1,0,0,3},{0,0,0,0},{0,0,0,0},{3,0,1,0}};
    cout << calc_dist(test2, make_pair(2,3), make_pair(0,3)) << endl;

    vector<vi> test3 = {{1,0,0,3},{0,0,0,0},{0,0,0,0},{3,0,1,0}};
    cout << calc_dist(test3, make_pair(0,3), make_pair(3,0)) << endl;

    vector<vi> test4 = {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,1,0}};
    cout << calc_dist(test4, make_pair(3,0), make_pair(3,2)) << endl;

    vector<vi> test5 = {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,1,0}};
    cout << calc_dist(test5, make_pair(3,2), make_pair(0,0)) << endl;
//    cout << solution({{1,2,0,0},{0,0,1,0},{0,0,0,0},{0,2,0,0}}, 1, 2) << endl;
    cout << solution({{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}}, 1, 0) << endl;
    //
//    cout << solution({{3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3}}, 0, 1) << endl;
    return 0;
}