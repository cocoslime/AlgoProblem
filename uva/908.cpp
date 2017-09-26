#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
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

ofstream fout("res.txt");
FILE* fp;

int N;
vector<vector<ii>> adjList; // <cost, dest>

priority_queue<ii> pq;
vector<bool> checked;

void process(int vtx){
    checked[0] = true;
    
    for (int i = 0 ; i < adjList[vtx].size() ; i++){
        int v = adjList[vtx][i].second;
        if (!checked[v]) pq.push(ii(-adjList[vtx][i].first,v));
    }
    
}

void prim(){
    int test_case; test_case = 0;
    while (cin >> N){
        adjList.clear();
        adjList.assign(N, vector<ii>());
        if (test_case != 0) fprintf(stdout, "\n");
        ll origin = 0;
        for (int i = 0 ; i < N - 1; i++){
            int src, dest;
            int cost;
            cin >> src >> dest >> cost;
            origin += cost;
        }
        
        int K; cin >> K;
        for (int i = 0 ; i < K ; i++){
            int src, dest;
            int cost;
            cin >> src >> dest >> cost;
            adjList[src - 1].push_back(make_pair(cost, dest - 1));
            adjList[dest - 1].push_back(make_pair(cost, src - 1));
        }
        
        int M; cin >> M;
        for (int i= 0 ; i < M ; i++){
            int src, dest;
            int cost;
            cin >> src >> dest >> cost;
            adjList[src - 1].push_back(make_pair(cost, dest - 1));
            adjList[dest - 1].push_back(make_pair(cost, src - 1));
        }
        
        checked.assign(N, false);
        process(0);
        ll ret = 0;
        
        while(pq.size() != 0){
            ii n_pair = pq.top();
            pq.pop();
            ret += (-n_pair.first);
            process(n_pair.second);
        }
        fprintf(stdout,"%lld\n%lld\n",origin,ret);
    }

    
}

int main(){
    //kruskal();
    prim();
    return 0;
}
