//
// Created by Dong's MacBook Pro on 2018. 4. 2..
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

int dp[1001][1001];

string str1;
string str2;
int N,M;

int func(int, int);
void track(int, int);

void track(int n, int m){
    int value = dp[n][m];
    if (value == ((int)(str1[n] == str2[m]) + func(n+1, m+1))){
        if (str1[n] == str2[m]) printf("%c", str1[n]);
        track(n+1, m+1);
    }
    else if (value == func(n, m+1)){
        track(n , m+1);
    }
    else if (value == func(n+1, m)){
        track(n+1, m);
    }
    else{
        return ;
    }
}

int func(int n, int m){
    if (n >= N || m >= M) return 0;
    int& result = dp[n][m];
    if (result != -1) return result;

    result = 0;
    result = max(result, (str1[n] == str2[m]) + func(n+1, m+1));
    result = max(result, func(n+1, m));
    result = max(result, func(n , m+1));

    return result;
}

int main(){
    cin >> str1;
    cin >> str2;

    N = str1.size();
    M = str2.size();

    memset(dp, -1, sizeof(dp));

    cout << func(0,0) << endl;
    track(0,0);
}