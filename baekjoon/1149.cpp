//
// Created by Dong's MacBook Pro on 2018. 3. 16..
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

#define MAX_N 1000

int cost[MAX_N][3];
int dp[MAX_N][3];
int N;

int func(int index, int currColor){
    if (index == N) return 0;
    if (dp[index][currColor] != -1) return dp[index][currColor];
    int result = INF;
    for (int i = 0 ; i < 3 ; i++){
        if (currColor != i)
            result = min(result, cost[index][currColor] + func(index+1, i) );
    }
    dp[index][currColor] = result;
    return result;
}

int main(){
    cin >> N;

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < 3; j++){
            cin >> cost[i][j];
            dp[i][j] = -1;
        }
    }

    int result = min(min(func(0, 0), func(0, 1)), func(0, 2));
    cout << result << endl;
    return 0;
}