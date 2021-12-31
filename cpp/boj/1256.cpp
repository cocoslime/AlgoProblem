

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
typedef unsigned long long ll;

#define INF 1000000000

ll dp[101][101];
int N, M;
ll K;

ll dict(int a_count, int z_count){
    if (dp[a_count][z_count] != 0) return dp[a_count][z_count];
    dp[a_count][z_count] = 0;
    ll res = 0;
    if (a_count == N && z_count == M){
        res = 1;
    }
    else if (a_count == N){
        // for (; z_count < M; z_count++) dp[a_count][z_count] = 1;
        res = dict(a_count, z_count + 1);
    }
    else if (z_count == M){
        // for (; a_count < N ; a_count++) dp[a_count][z_count] = 1;
        res = dict(a_count + 1, z_count);
    }
    else{
        res += dict(a_count + 1, z_count);
        res += dict(a_count , z_count + 1);
    }
    dp[a_count][z_count] = res;
    return res;
}

void printDict(int a_count, int z_count, ll num){
    ll res = dp[a_count][z_count];
    if (res < num){
        printf("-1");
        return;
    }
    if (a_count == N){
        for (; z_count < M; z_count++) printf("z");
    }
    else if (z_count == M){
        for (; a_count < N ; a_count++) printf("a");
    }
    else{
        ll a_num = dp[a_count+1][z_count];
        if (num <= a_num){
            printf("a");
            return printDict(a_count+1, z_count, num);
        }
        else{
            printf("z");
            return printDict(a_count, z_count+1, num - a_num);
        }
    }
}

int main(){
    //memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    cin >> K;
    for (int i = 0 ; i <= N ; i++){
        for (int j = 0 ; j <= M; j ++){
            dp[i][j] = 0;
        }
    }

    dict(0, 0);

    printDict(0, 0, K);
    return 0;
}
