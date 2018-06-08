//
// Created by Dong's MacBook Pro on 2018. 5. 14..
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
#include <cassert>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

ull K;
int N = 0;
ll cache[100][2];


ll func(int index, int isOne){
    ll& ret = cache[index][isOne];
    if (ret != -1) return ret;
    ret = 0;
    if (index == N) {
        ret = 1;
        return ret;
    }

    if (!isOne){
        ret += func(index + 1, 1);
    }
    ret += func(index + 1 , 0);
    return ret;
}

void printK(int index, int isOne, ll num){
    assert(num > 0);
    if (isOne)
        printf("%d", 1);
    else
        printf("%d", 0);
    if (index == N) return;

    if (isOne){
        printK(index + 1, 0, num);
    }
    else{
        if (cache[index + 1][0] < num){
            printK(index + 1, 1, num - cache[index + 1][0]);
        }
        else{
            printK(index + 1, 0, num);
        }
    }

}

int main(){
    std::fill(&cache[0][0], &cache[0][0] + sizeof(cache) / sizeof(cache[0][0]),
            -1);
    cin >> K;

    ll acc = 0;
    func(0, 1);
    while (acc + cache[0][1] < K){
        acc += cache[0][1];
        for (int i = N ; i >= 0 ; i--){
            cache[i+1][0] = cache[i][0];
            cache[i+1][1] = cache[i][1];
        }
        cache[0][1] = -1;
        N++;
        func(0, 1);
    }

    printK(0 , 1, K - acc);
    return 0;
}