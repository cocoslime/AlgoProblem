//
// Created by Dong's MacBook Pro on 2018. 3. 22..
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

#define MAX_N 1000000

int dp[MAX_N][2];
vector<int> adj[MAX_N], child[MAX_N];
bool checked[MAX_N];

int N;

void dfs(int curr){
    //printf("%d\n", curr);
    checked[curr] = true;
    for (int i = 0 ; i < adj[curr].size() ; i++){
        int next = adj[curr][i];
        if (!checked[next]){
            child[curr].push_back(next);
            dfs(next);
        }
    }
}


int sns(int index, int isEarly){
    //printf("index : %d, isEarly : %d\n", index, isEarly);
    int &result = dp[index][isEarly];
    if (result != -1)
        return result;

    if (isEarly){
        result = 1;
        for (int i = 0 ; i < child[index].size() ; i++){
            int next = child[index][i];
            result += min(sns(next, 1), sns(next, 0));
        }

        return result;
    }
    else{
        result = 0;
        for (int i = 0 ; i < child[index].size() ; i++){
            int next = child[index][i];
            result += sns(next, 1);
        }
        return result;
    }
}

int main(){
    cin >> N;
    for (int i = 0 ; i < N ; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    for (int i = 0 ; i < N - 1 ; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);

    int result = min(sns(0, 0), sns(0,1));
    printf("%d\n", result);
    return 0;
}