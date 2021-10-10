//
// Created by Dongmin on 2021/10/09.
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

using namespace std;


#define INF 1000000000
int max_x;
int max_y;

vector<pair<int, int>> direction = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

bool checkBoundary(int x, int y){
    if (x < max_x && x >= 0){
        if (y < max_y && y >= 0)
            return true;
    }
    return false;
}

bool backTracking(vector<vector<char>>& board, vector<vector<bool>> markBoard, int x, int y, string &word, int str_idx){
    if (word[str_idx] != board[x][y]) return false;
    if (word.size() - 1 == str_idx) return true;

    markBoard[x][y] = true;

    for (auto& dir : direction){
        int new_x = x + dir.first;
        int new_y = y + dir.second;

        if (checkBoundary(new_x, new_y)){
            if (!markBoard[new_x][new_y]){
                if (backTracking(board, markBoard, new_x, new_y, word, str_idx+1)){
                    return true;
                }
            }
        }
    }

    return false;
}

bool isNotNeighbor(vector<vector<char>>& board, char c1, char c2) {
    for (int i = 0 ; i < max_x ; i++) {
        for (int j = 0; j < max_y; j++) {
            if (board[i][j] == c1) {
                for (auto &dir: direction) {
                    int new_x = i + dir.first;
                    int new_y = j + dir.second;
                    if (checkBoundary(new_x, new_y)) {
                        if (board[new_x][new_y] == c2)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

bool isPossible(vector<vector<char>>& board, string word) {
    vector<bool> charExistMap(256, false);

    for (int i = 0 ; i < max_x ; i++) {
        for (int j = 0; j < max_y; j++) {
            int ascii = (int)board[i][j];
            charExistMap[ascii] = true;
        }
    }

    for (auto& c : word){
        if (!charExistMap[(int)c])
            return false;
    }

    for (int c_idx = 0 ; c_idx < word.length() - 1 ; c_idx++){
        char curr_c = word[c_idx];
        char next_c = word[c_idx + 1];

        if (!isNotNeighbor(board, curr_c, next_c))
            return false;
    }

    return true;
}


bool exist(vector<vector<char>>& board, string word) {
    max_x = board.size();
    max_y = board[0].size();

    if (!isPossible(board, word))
        return false;

    vector<vector<bool>> markBoard(max_x, vector<bool>(max_y, false));

    for (int i = 0 ; i < max_x ; i++){
        for (int j = 0 ; j < max_y ; j++){
            if (backTracking(board, markBoard, i, j, word, 0)){
                return true;
            }
        }
    }

    return false;
}

int main(){

    vector<vector<char>> board1 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << exist(board1, "ABCCED") << endl;
    cout << exist(board1, "SEE") << endl;
    cout << exist(board1, "ABCB") << endl;

    vector<vector<char>> board2 = {{'A','A','A','A','A','A'},
                                   {'A','A','A','A','A','A'},
                                   {'A','A','A','A','A','A'},
                                   {'A','A','A','A','A','A'},
                                   {'A','A','A','A','A','B'},
                                   {'A','A','A','A','B','A'}};
    cout << exist(board2, "AAAAAAAAAAAAABB") << endl;

    // DP Wrong!!..
    vector<vector<char>> board3 = {{'A','B','C','E'},
                                   {'S','F','E','S'},
                                   {'A','D','E','E'}};
    cout << exist(board3, "ABCESEEEFS") << endl;
    return 0;
}