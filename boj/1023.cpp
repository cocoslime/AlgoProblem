//
// Created by Dong's MacBook Pro on 2018. 5. 10..
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
typedef unsigned long long ull;

#define INF 1000000000
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
ull K;

ull dp[53][103][2]; //index, open, already_wrong(bin)

ull func_dp(int index, int open_count, int already_wrong){
    if (index == N){
        return (ull)(already_wrong || open_count != 0);
    }
    ull& res = dp[index][open_count + N][already_wrong];
    if (res != infl) return res;
    res = 0;
    res += func_dp(index+1, open_count+1, already_wrong);
    res += func_dp(index+1, open_count-1, already_wrong || open_count <= 0);

    return res;
}

void printK(int index, int open_count, int already_wrong, ull num){
    if (index == N) return;

    if (dp[index+1][open_count+1+N][already_wrong] >= num){
        if (num == 2 && N -1 == index) printf(")");
        else printf("(");
        printK(index+1, open_count+1, already_wrong, num);
    }
    else{
        printf(")");
        printK(index+1, open_count-1, already_wrong || open_count <= 0, num - dp[index+1][open_count+1+N][already_wrong]);
    }

}

int main(){

    memset(dp, 0x3c, sizeof(dp));
    scanf("%d%lld",&N,&K);

    func_dp(0, 0, 0);

    if (dp[0][N][0] < K + 1) return !printf("-1");
    printK(0, 0, 0, K + 1);

    return 0;
}
