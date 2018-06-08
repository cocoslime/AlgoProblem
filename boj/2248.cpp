//
// Created by Dong's MacBook Pro on 2018. 3. 23..
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

int N, L;
ll I;
ll dp[32][32];

ll bin(int index, int onebit){
    if (index == N) {
        dp[index][onebit] = 1;
        return 1;
    }
    ll& result = dp[index][onebit];
    if (result != -1) return result;

    result = 0;
    if (onebit < L) {
        result += bin(index + 1, onebit + 1);
    }
    result += bin(index + 1, onebit);

    return result;
}

void findIndex(int num, int index, int onebit){
    //printf("\n%d %d %d\n", num, index, onebit);
    if (index == N) return;
    if (dp[index+1][onebit] != -1 && dp[index+1][onebit] <= num){
        printf("%d", 1);
        findIndex(num - dp[index+1][onebit], index + 1, onebit + 1);
    }
    else{
        printf("%d", 0);
        findIndex(num, index + 1, onebit);
    }
}

int main(){
    cin >> N >> L >> I;
    memset(dp, -1, sizeof(dp));
    bin(0,0);

    /*
    for (int i = 0 ; i < N+1 ; i++){
        for (int j = 0 ; j < N + 1 ; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
     */
    findIndex(I - 1, 0, 0);
}