//
//  4196.cpp
//  algo
//
//  Created by Dong's MacBook Pro on 2017. 11. 9..
//  Copyright © 2017년 Dong's MacBook Pro. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS

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

#include <iostream>
#include <fstream>

vector<vi> adjList;
vi bfsn;
vector<bool> finished;
stack<int> S;
int M,N;
int cnt;

int dfs(int index){
    finished[index] = true;
    for (int next : adjList[index]){
        if (!finished[next]) dfs(next);
    }
    return 0;
}

int main(){
    int test_case; cin >> test_case;
    while (test_case--){
        cin >> N >> M;
        adjList.clear();
        adjList.assign(N, vi());
        finished.assign(N, false);
        for (int i = 0 ; i < M ; i++){
            int a,b;
            cin >> a >> b;
            adjList[a-1].push_back(b-1);
        }
        int count = 0;
        for (int i = 0 ; i < N ; i++){
            if (!finished[i]) {
                dfs(i);
                count ++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
