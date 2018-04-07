//
// Created by Dong's MacBook Pro on 2018. 4. 3..
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

#define INF 1000000000

vector<vi> adjList;
vi result_vector;
int value[10001];
int dp[10001][2];
bool checked[10001];

int N;

int bfs(int, int);

void printSet(int curr, int c){
    int pick, nonpick;
    if (curr == -1){
        pick = bfs(0, 1);
        nonpick = bfs(0, 0);
        if (pick > nonpick) {
            result_vector.push_back(0);
            printSet(0, 1);
        }
        else{
            printSet(0, 0);
        }
    }
    else{
        checked[curr] = true;
        for (int next : adjList[curr]){
            if (!checked[next]){
                pick = 0;
                if (c == 0){
                    pick = bfs(next, 1);
                }
                nonpick = bfs(next, 0);
                if (pick > nonpick) {
                    result_vector.push_back(next);
                    printSet(next, 1);
                }
                else{
                    printSet(next, 0);
                }
            }
        }
        checked[curr] = false;
    }
}

int bfs(int index, int c){
    // cout << index << ", " << c << endl;
    int& result = dp[index][c];
    if (result != -1) return result;
    if (c == 1) result = value[index];
    else result = 0;

    checked[index] = true;
    for (int i = 0 ; i < adjList[index].size(); i++){
        int child = adjList[index][i];
        if (!checked[child]){
            int child_result = 0;
            if (c == 0){
                child_result = bfs(child, 1);
            }
            child_result = max(child_result, bfs(child, 0));
            result += child_result;
        }
    }
    checked[index] = false;
    return result;
}

int main(){
    cin >> N;
    adjList.assign(N, vi());
    for (int i = 0 ; i < N ; i++){
        int v;
        cin >> v;
        value[i] = v;
    }
    for (int i = 0 ; i < N -1; i++){
        int src, dest;
        cin >> src >> dest;
        adjList[src-1].push_back(dest-1);
        adjList[dest-1].push_back(src-1);
    }
    memset(checked, false, 10001);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", max(bfs(0, 0), bfs(0,1)));

    memset(checked, false, 10001);
    printSet(-1, 0);

    sort(result_vector.begin(), result_vector.end());
    for (int i = 0 ; i < result_vector.size() ; i++){
        printf("%d ", result_vector[i]+1);
    }
    return 0;
}